
#include "Dispatcher.hpp"
#include <cstdio>

Dispatcher::Dispatcher() {
	int num_threads = std::thread::hardware_concurrency();
	for (int i = 0; i < num_threads; ++i) {
		auto worker = [this]() {
			while (true) {
				std::function<void()> task;
				{
					std::unique_lock<std::mutex> lock{ task_mutex_ };
					mutex_condition_.wait(lock, [this] { return !task_queue_.empty() || stop_; });
					if (task_queue_.empty() && stop_) return;
					task = std::move(task_queue_.front());
					task_queue_.pop();
				}
				task();
			}
		};
		thread_vector_.push_back(std::thread{ std::move(worker) });
	}
}

Dispatcher::~Dispatcher() {
	stop_ = true;
	mutex_condition_.notify_all();
	for (int i = 0; i < thread_vector_.size(); ++i)
		thread_vector_[i].join();

	thread_vector_.clear();
}


void Dispatcher::Add(std::function<void()> task) {
	{
		std::unique_lock<std::mutex> lock{ task_mutex_ };
		task_queue_.emplace(task);
	}
	mutex_condition_.notify_one();
}


