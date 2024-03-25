
#ifndef __RENDERSYSTEM_HPP__
#define __RENDERSYSTEM_HPP__

#include "ECS.hpp"
#include "Material.hpp"
#include "Camera.hpp"

class RenderSystem {
public:
	RenderSystem();
	virtual ~RenderSystem();

	void exec(ComponentManager&, Camera&) const;
};

#endif