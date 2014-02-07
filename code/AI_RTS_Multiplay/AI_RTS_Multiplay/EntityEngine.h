#pragma once

#include <vector>
#include <unordered_set>

#include "Entity.h"

class EntityEngine
{
public:
	EntityEngine(void);
	~EntityEngine(void);
	entity_id getNewEntity(void);
	bool deleteEntity(entity_id);
	Entity* getEntity(entity_id);
	std::vector<Entity*> getEntitys(component_id);
	
private:
	std::vector<Entity> entities_;
	std::unordered_set<entity_id> freeIds_;
};

