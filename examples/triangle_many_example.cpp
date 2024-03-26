
#include "Window.hpp"
#include "ECS.hpp"
#include "ResourceManager.hpp"
#include "RenderSystem.hpp"
#include "Input.hpp"

#include "Shader.hpp"
#include "Geometry.hpp"
#include "Material.hpp"

#include <memory>
#include <string>

#include "gtc/matrix_transform.hpp"
#include "imgui.h"

int main(int, char**) {

	Engine::Window* window = Engine::Window::Create("Window Example", 640, 480);
	if (nullptr == window) {
		return -1;
	}

	Engine::Input input;
	ResourceManager resource_manager;
	ComponentManager component_manager;
	RenderSystem render;

	component_manager.AddComponentClass<Material>();
	auto material_entity = component_manager.NewEntity();
	auto mat_comp = component_manager.AddEntityComponent<Material>(material_entity);

	mat_comp->shader = resource_manager.CreateShader("../assets/shaders/vertex.glslv", "../assets/shaders/fragment.glslf");
	mat_comp->geometry = resource_manager.CreateGeometry();

	auto triangle_transform = component_manager.GetEntityComponent<Transform>(material_entity);
	triangle_transform->world_model = glm::mat4(1.0f);
	triangle_transform->world_model = glm::translate(triangle_transform->world_model, glm::vec3(0.0f, 0.0f, 0.0f));

	Camera camera;
	camera.SetupInput(input);
	input.SetupInput(window->window());
	while (!window->isOpen()) {

		window->BeginFrame();
		window->Clear();

		render.exec(component_manager, camera);

		window->EndFrame();
	}

	return 0;
}
