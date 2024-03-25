
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

#endif