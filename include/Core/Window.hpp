
#pragma once

#define GLFW_INCLUDE_NONE

#include "glfw3.h"

#include <cstdint>
#include <utility>
#include <optional>

namespace Engine {

	class Window {
	public:
		~Window();
		Window(Window&);
		Window(Window&&);

		uint32_t isOpen() const;
		static Window* Create(const char* title, uint32_t screnn_w, uint32_t screen_h);

		void BeginFrame() const;
		void Clear() const;
		void EndFrame() const;

		GLFWwindow* window() { return window_; }

	private:
		Window();
		Window(const Window&) = delete;
		GLFWwindow* window_;

	};

} // end namepsace Engine