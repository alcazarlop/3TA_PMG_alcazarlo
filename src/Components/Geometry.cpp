
#include "Geometry.hpp"
#include <cmath>

void CreateTriangle(std::shared_ptr<Geometry>& geometry) {
	
	float vertices[9]{
		-0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
	};

	unsigned int indices[3] = {
		0 ,1 ,2
	};

	geometry.get()->indices_size = sizeof(indices);

	glGenVertexArrays(1, &geometry.get()->VAO);
	glGenBuffers(1, &geometry.get()->VBO);
	glGenBuffers(1, &geometry.get()->EBO);

	glBindVertexArray(geometry.get()->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, geometry.get()->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geometry.get()->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

void CreateSphere(std::shared_ptr<Geometry>& geometry) {



}

void CreateCube(std::shared_ptr<Geometry>& geometry) {

}

void LoadMesh(std::shared_ptr<Geometry>& geometry) {

	
}