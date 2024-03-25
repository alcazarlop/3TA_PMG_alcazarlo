
#include "RenderSystem.hpp"
#include "glew.h"
#include "gtc/matrix_transform.hpp"
#include "glfw3.h"


RenderSystem::RenderSystem() {

}

RenderSystem::~RenderSystem() {

}

void RenderSystem::exec(ComponentManager& cm, Camera& camera) const {

	auto mat_list = cm.GetComponentList<Material>();
	auto tr_list = cm.GetComponentList<Transform>();

	for (unsigned int i = 0; i < mat_list.size(); ++i) {
		if (mat_list[i].has_value()) {
			glUseProgram(mat_list[i]->shader->program_id);

			GLuint model = glGetUniformLocation(mat_list[i]->shader->program_id, "model");
			tr_list[i]->world_model = glm::rotate(tr_list[i]->world_model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			glUniformMatrix4fv(model, 1, GL_FALSE, &tr_list[i]->world_model[0][0]);

			camera.Update(mat_list[i]->shader);

			glBindVertexArray(mat_list[i]->geometry->VAO);
			glDrawElements(GL_TRIANGLES, mat_list[i]->geometry->indices_size / sizeof(unsigned int), GL_UNSIGNED_INT, 0);
		}
	}
}
