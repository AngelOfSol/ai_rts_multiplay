#include "Entity.h"


Entity::Entity(entity_id e_id):id_(e_id), currentComponents_(0)
{
}


Entity::~Entity(void)
{
}

Component* Entity::getComponent(component_id c_id)
{
	for(auto iter = this->components_.begin(); iter != this->components_.end(); iter++)
	{
		if((*iter)->type_id == c_id)
		{
			return *iter;
		}
	}
	return NULL;
}

bool Entity::addComponent(Component* component)
{
	if((this->currentComponents_ & component->type_id) == 0)
	{
		this->components_.push_back(component); 
		return true;
	} else
	{
		return false;
	}
}

bool Entity::removeComponent(component_id c_id)
{
	if(this->hasComponents(c_id))
	{
		for(auto iter = this->components_.begin(); iter != this->components_.end(); iter++)
		{
			if((*iter)->type_id == c_id)
			{
				Component * toDelete = *iter;
				this->components_.erase(iter);
				delete toDelete;
				toDelete = 0;
				return true;
			}
		}
		return false;
	}
	{
		return false;
	}
}

bool Entity::hasComponents(component_id c_id) const
{
	return (this->currentComponents_ & c_id) == c_id;
}

void Entity::removeAllComponents()
{
	this->components_.clear();
	this->currentComponents_ = 0;
}