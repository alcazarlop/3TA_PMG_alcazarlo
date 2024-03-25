
#include "Input.hpp"
#include "Keycodes.hpp"

using namespace Engine;

std::map<std::pair<KeyCode, InputAction>, std::vector<std::function<void()>>> Input::KeyMap;

Input::Input() {
	
}

Input::~Input() {
	KeyMap.clear();
}


void Input::BindAction(KeyCode key, InputAction action, std::function<void()> callback) {
	auto token = std::make_pair(key, action);
	KeyMap[token].push_back(callback);
}

void Input::HandleInput(GLFWwindow* window, int key, int scancode, int action, int mods) {
	auto token = std::make_pair((KeyCode)key, (InputAction)action);
	for (auto& value : KeyMap[token]) {
		value();
	}
}

void Input::SetupInput(GLFWwindow* window) {
	glfwSetKeyCallback(window, HandleInput);
}

