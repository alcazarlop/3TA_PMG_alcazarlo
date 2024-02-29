
#ifndef __MATERIAL_HPP__
#define __MATERIAL_HPP__

#include <vector>
#include <memory>
#include <gl/glew.h>

#include "Texture.hpp"

struct Material {
	GLuint program_id;
	std::vector<std::shared_ptr<Texture>> textures;
};

void LoadShader(std::shared_ptr<Material>&);

#endif