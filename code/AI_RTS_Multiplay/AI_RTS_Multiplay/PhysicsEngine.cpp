#include "PhysicsEngine.h"


PhysicsEngine::PhysicsEngine(void)
{
}


PhysicsEngine::~PhysicsEngine(void)
{
}

void PhysicsEngine::update(const sf::Time& elapsed)
{
	for(auto objectIter = this->objects_.begin(); objectIter != this->objects_.end(); objectIter++)
	{
		(*objectIter)->acceleration() = sf::Vector2f();
		for(auto forceIter = this->forces_.begin(); forceIter != this->forces_.end(); forceIter++)
		{
			(*forceIter)->actOn(*objectIter);
		}
		(*objectIter)->update(elapsed);
	}
}