#include "Component.h"


Component::Component(std::string name):type_id
	(
		// check to see if we've already created a component id for this class
		Component::idList_.count(name) == 1 ? 
		// we have so use it
		Component::idList_[name] : 
		// we haven't so create a new one
		// component_ids take up a single bit, allowing easy class identification
		// ex: the first component subclass created will have an id of 1 (00000001)
		// the second component subclass created will have an id of 2 (00000010)
		// and the third component subclass created will have an id of 4 (00000100)
		// and so on
		// WHY:
		// this prevents both duplicate class ids, and allows you to create the components in any order you wish
		Component::idList_[name] = 1 << nextId_++
	)
{
}


Component::~Component(void)
{
}

int Component::nextId_ = 0;
std::unordered_map<std::string, component_id> Component::idList_;