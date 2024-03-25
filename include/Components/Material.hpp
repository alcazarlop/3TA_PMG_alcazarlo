
#ifndef __MATERIAL_HPP__
#define __MATERIAL_HPP__

#include "Geometry.hpp"
#include "Shader.hpp"

#include <memory>

struct Material {
	std::shared_ptr<Shader> shader;
	std::shared_ptr<Geometry> geometry;
};

#endif