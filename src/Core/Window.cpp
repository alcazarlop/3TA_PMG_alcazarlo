
#include "Window.hpp"

#include "GL/glew.h"

using namespace Engine;

Window::Window() {
	glfwInit();
	window_ = nullptr;
}

Window::Window(Window& w) {
	window_ = w.window_;
}

Window::Window(Window&& w) {
	window_ = w.window_;
}

Window::~Window() {
	if (nullptr != window_)
		glfwDestroyWindow(window_);
	glfwTerminate();
}

uint32_t Window::isOpen() const {
	return glfwWindowShouldClose(window_);
}

Window* Window::Create(const char* title, uint32_t screen_w, uint32_t screen_h) {
	Window* ww = new Window();
	ww->window_ = glfwCreateWindow(screen_w, screen_h, title, nullptr, nullptr);
	if (nullptr == ww->window_) {
		printf("Error! Could not initialize Window\n");
		return nullptr;
	}
	glfwMakeContextCurrent(ww->window_);
	glewInit();
	return ww;
}

void Window::Swap() const {
	glfwSwapBuffers(window_);
}

void Window::Clear() const {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::EndFrame() const {
	glfwPollEvents();
}
