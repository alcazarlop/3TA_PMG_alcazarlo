
#ifndef __RESOURCE_MANAGER_HPP__
#define __RESOURCE_MANAGER_HPP__

#include <memory>
#include <string>
#include <cassert>

#include "Shader.hpp"
#include "Geometry.hpp"


class ResourceManager {
public:
	ResourceManager();
	~ResourceManager();

	std::string ReadFile(const char* file_path);

	std::shared_ptr<Shader> CreateShader(const char* vs, const char* fs);
	std::shared_ptr<Geometry> CreateGeometry();

	std::shared_ptr<Geometry> LoadMesh(const char* path);

};





#endif