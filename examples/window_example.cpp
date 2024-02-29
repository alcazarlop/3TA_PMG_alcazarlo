
#include "Window.hpp"

int main(int, char**) {

	Engine::Window* window = Engine::Window::Create("Window Example", 640, 480);
	if(nullptr == window){
		return -1;
	}

	while (!window->isOpen()) {
		window->Clear();
		window->Swap();
		window->EndFrame();
	}

	return 0;
}
