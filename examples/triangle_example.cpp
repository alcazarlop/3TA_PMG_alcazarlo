
#include "Window.hpp"
#include "ECS.hpp"
#include "RenderComponent.hpp"
#include "TransformComponent.hpp"
#include "gtc/matrix_transform.hpp"

#include <memory>

int main(int, char**) {

	Engine::Window* window = Engine::Window::Create("Window Example", 640, 480);
	if(nullptr == window){
		return -1;
	}

	ComponentManager CM;

	CM.AddComponentClass<RenderComponent>();
	size_t triangle = CM.NewEntity();
	CM.AddEntityComponent<RenderComponent>(triangle);

	auto triangle_render = CM.GetEntityComponent<RenderComponent>(triangle);
	triangle_render->geometry = std::make_shared<Geometry>();
	triangle_render->material = std::make_shared<Material>();
	triangle_render->camera = std::make_shared<Camera>();

	triangle_render->camera->view_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -4.0f));
	triangle_render->camera->projection_matrix = glm::mat4(1.0f);
	triangle_render->camera->projection_matrix = glm::perspective(glm::radians(45.0f), 640.0f / 480.0f, 0.2f, 100.0f);

	auto triangle_transform = CM.GetEntityComponent<TransformComponent>(triangle);
	triangle_transform->model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -4.0f));

	LoadShader(triangle_render->material);
	CreateTriangle(triangle_render->geometry);

	while (!window->isOpen()) {

		window->Clear();

		RenderSystem(CM.GetComponentList<RenderComponent>(), CM.GetComponentList<TransformComponent>());

		window->Swap();
		window->EndFrame();
	}

	return 0;
}
