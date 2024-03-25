
#pragma once

#define GLFW_INCLUDE_NONE

#include "glfw3.h"
#include <cstdint>
#include <map>
#include <vector>
#include <functional>
#include <utility>

#include "Window.hpp"
#include "Keycodes.hpp"

namespace Engine {

	class Input {
	public:
		Input();
		~Input();

		void BindAction(KeyCode key, InputAction action, std::function<void()> callback);
		static void HandleInput(GLFWwindow* window, int key, int scancode, int action, int mod);
		void SetupInput(GLFWwindow*);

	private:
		static std::map<std::pair<KeyCode, InputAction>, std::vector<std::function<void()>>> KeyMap;
	};

} // end namepsace Engine