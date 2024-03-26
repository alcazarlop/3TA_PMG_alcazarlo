
#include "Window.hpp"

#include "GL/glew.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

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
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

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
	glfwSwapInterval(1);
	glewInit();

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	ImGui_ImplGlfw_InitForOpenGL(ww->window_, true);
	ImGui::StyleColorsDark();
	ImGui_ImplOpenGL3_Init("#version 330 core");

	return ww;
}

void Window::BeginFrame() const {
	glfwPollEvents();
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Window::Clear() const {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::EndFrame() const {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(window_);
}
