#pragma once
#include <list>
#include "Component.h"

typedef unsigned long int entity_id;
class Entity
{
public:
	~Entity(void);
	bool addComponent(Component* );
	bool removeComponent(component_id);
	Component* getComponent(component_id);
	bool hasComponents(component_id) const;
	void removeAllComponents();
private:
	friend class EntityEngine;
	Entity(entity_id);
	std::list<Component*> components_;
	const entity_id id_;
	component_id currentComponents_;
	static entity_id new_id;
};
/*
have list of all entity ids
have list of all component ids
write optimized vector class for deletion of ids
map ids to each other






*/