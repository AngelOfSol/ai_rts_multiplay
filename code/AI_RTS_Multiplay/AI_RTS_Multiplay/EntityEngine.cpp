#include "EntityEngine.h"


EntityEngine::EntityEngine(void)
{
}


EntityEngine::~EntityEngine(void)
{
}

entity_id EntityEngine::getNewEntity(void)
{
	if(this->freeIds_.size() == 0)
	{
		int newId = this->entities_.size();
		this->entities_.push_back(Entity(newId));
		return newId;
	} else
	{
		int newId = *this->freeIds_.begin();
		this->freeIds_.erase(this->freeIds_.begin());
		this->entities_[newId].removeAllComponents();
		return newId;
	}
}

bool EntityEngine::deleteEntity(entity_id e_id)
{
	if(this->freeIds_.count(e_id) == 0)
	{
		this->freeIds_.insert(e_id);
		return true;
	} else
	{
		return false;
	}
}

Entity* EntityEngine::getEntity(entity_id e_id)
{
	if(this->freeIds_.count(e_id) == 0)
	{
		return &this->entities_[e_id];
	} else
	{
		return NULL;
	}
}
std::vector<Entity*> EntityEngine::getEntitys(component_id c_id)
{
	std::vector<Entity*> ret;
	for(auto iter = this->entities_.begin(); iter != this->entities_.end(); iter++)
	{
		if(this->freeIds_.count(iter->id_) == 0 && iter->hasComponents(c_id))
		{
			ret.push_back(&(*iter));
		}
	}
	return ret;
}