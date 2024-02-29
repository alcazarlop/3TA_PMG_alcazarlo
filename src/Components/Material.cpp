
#include "Material.hpp"
#include <iostream>

void LoadShader(std::shared_ptr<Material>& material) {

	const char* vertexSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"uniform mat4 projection;\n"
		"uniform mat4 view;\n"
		"uniform mat4 model;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
		"}\n\0";

	const char* fragmentSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	material.get()->program_id = glCreateProgram();
	glAttachShader(material.get()->program_id, vertexShader);
	glAttachShader(material.get()->program_id, fragmentShader);
	glLinkProgram(material.get()->program_id);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}