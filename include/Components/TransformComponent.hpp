
#ifndef __TRANSFORMCOMPONENT_HPP__
#define __TRANSFORMCOMPONENT_HPP__

#include "glm.hpp"
#include <optional>
#include <vector>

struct TransformComponent {
	glm::mat4 model;
	glm::mat4 model_parent;
};

#endif