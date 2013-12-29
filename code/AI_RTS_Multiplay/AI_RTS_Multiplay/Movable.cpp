#include "Movable.h"


Movable::Movable(float mass): position_(), velocity_(), acceleration_(), mass_(mass)
{
}


Movable::~Movable(void)
{
}

void Movable::update(const sf::Time& elapsed)
{
	this->velocity_ += this->acceleration_ * elapsed.asSeconds();
	this->position_ += this->velocity_ * elapsed.asSeconds();
	//this->roundOff();
}

void Movable::roundOff(void)
{
	this->acceleration_.x = (int)(this->acceleration_.x * 1000.0f) / 1000.0f;
	this->acceleration_.y = (int)(this->acceleration_.y * 1000.0f) / 1000.0f;
	
	this->velocity_.x = (int)(this->velocity_.x * 1000.0f) / 1000.0f;
	this->velocity_.y = (int)(this->velocity_.y * 1000.0f) / 1000.0f;
	
	this->position_.x = (int)(this->position_.x * 1000.0f) / 1000.0f;
	this->position_.y = (int)(this->position_.y * 1000.0f) / 1000.0f;
}

void Movable::applyForce(const sf::Vector2f& force)
{
	this->acceleration_ += force / this->mass_;
}