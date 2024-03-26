
#include "ResourceManager.hpp"
#include "glew.h"

#include <sstream>
#include <fstream>
#include <utility>

ResourceManager::ResourceManager() {
	

}

ResourceManager::~ResourceManager() {


}

std::string ResourceManager::ReadFile(const char* file_path) {
	std::ifstream file(file_path, std::ios::binary);
	assert(file && "File not found!");

	std::string contents;
	file.seekg(0, std::ios::end);
	contents.resize(file.tellg());
	file.seekg(0, std::ios::beg);
	file.read(&contents[0], contents.size());
	file.close();
	return(contents);
}

std::shared_ptr<Shader> ResourceManager::CreateShader(const char* vs, const char* fs) {
	std::shared_ptr<Shader> new_shader = std::make_shared<Shader>();

	std::string vertexFile = ReadFile(vs);
	std::string fragFile = ReadFile(fs);

	const char* vertexSource = vertexFile.c_str();
	const char* fragSource = fragFile.c_str();

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glShaderSource(fragShader, 1, &fragSource, NULL);

	glCompileShader(vertexShader);
	glCompileShader(fragShader);

	unsigned int program_id = glCreateProgram();

	glAttachShader(program_id, vertexShader);
	glAttachShader(program_id, fragShader);
	glLinkProgram(program_id);

	glDeleteShader(vertexShader);
	glDeleteShader(fragShader);

	new_shader->program_id = program_id;
	return new_shader;
}

std::shared_ptr<Geometry> ResourceManager::CreateGeometry() {
	std::shared_ptr<Geometry> new_geometry = std::make_shared<Geometry>();

	float vertices[9]{
		-0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
	};

	unsigned int indices[3] = {
		0 ,1 ,2
	};

	new_geometry->indices_size = sizeof(indices);

	glGenVertexArrays(1, &new_geometry->VAO);
	glGenBuffers(1, &new_geometry->VBO);
	glGenBuffers(1, &new_geometry->EBO);

	glBindVertexArray(new_geometry->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, new_geometry->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, new_geometry->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	return new_geometry;
}

std::shared_ptr<Geometry> ResourceManager::LoadMesh(const char* path) {

	return std::make_shared<Geometry>();
}

