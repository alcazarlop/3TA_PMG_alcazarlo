#include "ECS.hpp"

size_t ComponentManager::NewEntity() {
	size_t entity = 0;
	for (auto& [key, value] : component_list_map) {
		entity = value->Size();
		value->Emplace();
	}
	AddEntityComponent<Transform>(entity);
	return entity;
}
