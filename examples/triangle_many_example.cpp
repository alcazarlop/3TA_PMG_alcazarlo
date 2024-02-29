
#include "Window.hpp"
#include "ECS.hpp"
#include "RenderComponent.hpp"
#include "TransformComponent.hpp"
#include "gtc/matrix_transform.hpp"


int main(int, char**) {

	Engine::Window* window = Engine::Window::Create("Window Example", 640, 480);
	if(nullptr == window){
		return -1;
	}

	const unsigned int totalEntities = 10;

	ComponentManager cm;
	cm.AddComponentClass<RenderComponent>();
	
	size_t entity[totalEntities];
	for (int i = 0; i < totalEntities; ++i) {
		entity[i] = cm.NewEntity();
		cm.AddEntityComponent<RenderComponent>(entity[i]);

		auto triangle_render = cm.GetEntityComponent<RenderComponent>(entity[i]);
		triangle_render->material = std::make_shared<Material>();
		triangle_render->geometry = std::make_shared<Geometry>();
		triangle_render->camera = std::make_shared<Camera>();

		triangle_render->camera->view_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -4.0f));
		triangle_render->camera->projection_matrix = glm::mat4(1.0f);
		triangle_render->camera->projection_matrix = glm::perspective(glm::radians(45.0f), 640.0f / 480.0f, 0.2f, 100.0f);

		LoadShader(triangle_render->material);
		CreateTriangle(triangle_render->geometry);
	}

	while (!window->isOpen()) {

		window->Clear();

		for (int i = 0; i < totalEntities; ++i) {
			auto triangle_transform = cm.GetEntityComponent<TransformComponent>(entity[i]);
			triangle_transform->model = glm::mat4(1.0f);
			triangle_transform->model = glm::translate(triangle_transform->model, glm::vec3(-5.0f + (float)((i % 5) * 2.5f), (float)((i / 5) * 2.5f), -10.0f));
			triangle_transform->model = glm::rotate(triangle_transform->model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		}

		RenderSystem(cm.GetComponentList<RenderComponent>(), cm.GetComponentList<TransformComponent>());

		window->Swap();
		window->EndFrame();
	}

	return 0;
}
