
#ifndef __ECS_HPP__
#define __ECS_HPP__

#include <functional>
#include <optional>
#include <iostream>
#include <cassert>

#include "Transform.hpp"

struct BaseComponentList {
	virtual void Emplace() = 0;
	virtual size_t Size() = 0;
};

template<typename T>
struct ComponentList : BaseComponentList {
	std::vector<std::optional<T>> components;

	virtual void Emplace(){ components.emplace_back(); }
	virtual size_t Size() { return components.size(); }
};

struct ComponentManager {
	ComponentManager() {
		AddComponentClass<Transform>();
	}

	~ComponentManager() {}

	template<typename T> void AddComponentClass();
	template<typename T> T* AddEntityComponent(size_t entity);
	template<typename T> T* GetEntityComponent(size_t entity);
	template<typename T> std::vector<std::optional<T>>& GetComponentList();

	size_t NewEntity();

	std::unordered_map<size_t, std::unique_ptr<BaseComponentList>> component_list_map;
};

template<typename T> void ComponentManager::AddComponentClass() {
	auto key = typeid(T).hash_code();
	assert(!component_list_map.contains(key) && "Already contains the component");
	component_list_map.emplace(key, std::make_unique<ComponentList<T>>());

	auto map_iterator = component_list_map.find(key);
	auto& component_list_ref = *static_cast<ComponentList<T>*>(map_iterator->second.get());

	if(component_list_map.size() != 1){
		auto size = component_list_map.begin()->second->Size();
		for (size_t i = 0; i < size; ++i) {
			component_list_ref.Emplace();
		}
	}
}

template<typename T> T* ComponentManager::AddEntityComponent(size_t entity) {
	auto hash_code = typeid(T).hash_code();
	assert(component_list_map.contains(hash_code));
	auto component_list_iterator = component_list_map.find(hash_code);
	auto& component_list_ref = *static_cast<ComponentList<T>*>(component_list_iterator->second.get());
	auto& component_opt = component_list_ref.components.at(entity);
	component_opt = T();
	return &component_opt.value();
}

template<typename T> T* ComponentManager::GetEntityComponent(size_t entity) {
	auto hash_code = typeid(T).hash_code();
	assert(component_list_map.contains(hash_code));
	auto component_list_iterator = component_list_map.find(hash_code);
	auto& component_list_ref = *static_cast<ComponentList<T>*>(component_list_iterator->second.get());
	auto& component_opt = component_list_ref.components.at(entity);

	if (!component_opt.has_value()) 
		return nullptr;

	return &component_opt.value();
}

template<typename T> std::vector<std::optional<T>>& ComponentManager::GetComponentList() {
	auto hash_code = typeid(T).hash_code();
	assert(component_list_map.contains(hash_code));
	auto component_list_iterator = component_list_map.find(hash_code);
	auto& component_list_ref = *static_cast<ComponentList<T>*>(component_list_iterator->second.get());
	return component_list_ref.components;
}

#endif