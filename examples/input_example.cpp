
#include "Window.hpp"
#include "Input.hpp"

#include <cstdio>

void Foo() {
	printf("Funciona!\n");
}

void Bar() {
	printf("Bar\n");
}

void Release() {
	printf("Release\n");
}

void Pressed() {
	printf("Pressed\n");
}

int main(int, char**) {

	Engine::Input input;

	Engine::Window* window = Engine::Window::Create("Window Example", 640, 480);
	if(nullptr == window){
		return -1;
	}

	input.SetupInput(window->window());
	input.BindAction(Space, IA_Pressed, Foo);
	input.BindAction(Space, IA_Repeat, Pressed);
	input.BindAction(Space, IA_Released, Release);
	input.BindAction(W, IA_Pressed, Bar);
	input.BindAction(O, IA_Repeat, Pressed);

 	while (!window->isOpen()) {
		window->Clear();
		window->Swap();

		window->EndFrame();
	}

	return 0;
}
