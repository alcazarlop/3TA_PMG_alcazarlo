
#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include "glm.hpp"

struct Camera {
	glm::mat4 view_matrix;
	glm::mat4 projection_matrix;
};

#endif