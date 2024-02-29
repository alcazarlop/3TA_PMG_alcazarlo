
#include "RenderComponent.hpp"

#include "glew.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#include "Camera.hpp"
#include "TransformComponent.hpp"


void RenderSystem(std::vector<std::optional<RenderComponent>>& render_list, std::vector<std::optional<TransformComponent>>& transform_list) {
	for (int i = 0; i < render_list.size(); ++i) {
		glUseProgram(render_list[i].value().material.get()->program_id);

		GLuint model = glGetUniformLocation(render_list[i].value().material.get()->program_id, "model");
		GLuint view = glGetUniformLocation(render_list[i].value().material.get()->program_id, "view");
		GLuint projection = glGetUniformLocation(render_list[i].value().material.get()->program_id, "projection");
		
		glUniformMatrix4fv(model, 1, GL_FALSE, &transform_list[i].value().model[0][0]);
		glUniformMatrix4fv(view, 1, GL_FALSE, &render_list[i].value().camera->view_matrix[0][0]);
		glUniformMatrix4fv(projection, 1, GL_FALSE, &render_list[i].value().camera->projection_matrix[0][0]);

		glBindVertexArray(render_list[i].value().geometry.get()->VAO);
		glDrawElements(GL_TRIANGLES, render_list[i].value().geometry.get()->indices_size / sizeof(unsigned int), GL_UNSIGNED_INT, 0);
	}

}

