#include "Drag.h"


Drag::Drag(float dragCoefficent):dragCoefficent_(dragCoefficent)
{
}


Drag::~Drag(void)
{
}

void Drag::actOn(Movable* target) const
{
	float speed = std::sqrt(std::powf(target->velocity().x, 2.0f) +  std::powf(target->velocity().y, 2.0f));
	float force = speed * this->dragCoefficent_; 
	float angle = atan2(target->velocity().y, target->velocity().x);
	sf::Vector2f forceVec;
	forceVec.x -= force * cosf(angle);
	forceVec.y -= force * sinf(angle);
	target->applyForce(forceVec);
}