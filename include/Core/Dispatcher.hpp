
#pragma once

#include <queue>
#include <functional>
#include <future>
#include <thread>

class Dispatcher {
public:
	Dispatcher();
	~Dispatcher();

	void Add(std::function<void()> task);

private:
	Dispatcher(Dispatcher&) = delete;
	Dispatcher(const Dispatcher&) = delete;
	Dispatcher& operator=(Dispatcher&) = delete;

	std::vector<std::thread> thread_vector_;
	std::queue<std::function<void()>> task_queue_;
	std::mutex task_mutex_;
	std::condition_variable mutex_condition_;

	bool stop_ = false;
};

