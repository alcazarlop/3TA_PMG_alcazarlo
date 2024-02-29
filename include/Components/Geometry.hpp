
#ifndef __GEOMETRY_HPP__
#define __GEOMETRY_HPP__

#include <memory>
#include <gl/glew.h>

struct Geometry {
	GLuint VBO;
	GLuint VAO;
	GLuint EBO;
	GLuint indices_size;
};

void CreateTriangle(std::shared_ptr<Geometry>&);
void CreateSphere(std::shared_ptr<Geometry>&);
void CreateCube(std::shared_ptr<Geometry>&);

void LoadMesh(std::shared_ptr<Geometry>&);

#endif