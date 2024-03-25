
#include "Window.hpp"
#include "Dispatcher.hpp"

#include <cstdio>

int g_counter = 0;

void Foo() {
	g_counter++;
	printf("Ejecutando Foo: %d\n", g_counter);
}

void Bar() {
	g_counter++;
	printf("Ejecutanto Bar: %d\n", g_counter);
}

int main(int, char**) {

	Engine::Window* window = Engine::Window::Create("Window Example", 640, 480);
	if(nullptr == window){
		return -1;
	}

	Dispatcher dispatcher;

	while (!window->isOpen()) {
		window->Clear();

		dispatcher.Add(Bar);
		dispatcher.Add(Foo);

		window->Swap();
		window->EndFrame();
	}

	return 0;
}
