
#ifndef __RENDERCOMPONENT_HPP__
#define __RENDERCOMPONENT_HPP__

#include <memory>
#include <optional>

#include "Geometry.hpp"
#include "Material.hpp"
#include "Camera.hpp"
#include "TransformComponent.hpp"

struct RenderComponent {
	std::shared_ptr<Material> material;
	std::shared_ptr<Geometry> geometry;
	std::shared_ptr<Camera> camera;
};

void RenderSystem(std::vector<std::optional<RenderComponent>>&, std::vector<std::optional<TransformComponent>>&);

#endif