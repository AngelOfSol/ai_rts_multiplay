#include "Current.h"


Current::Current(const sf::Vector2f& force):force_(force)
{
}


Current::~Current(void)
{
}

void Current::actOn(Movable* target) const
{
	target->applyForce(this->force_);
}