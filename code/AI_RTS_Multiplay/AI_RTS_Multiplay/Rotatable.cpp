#include "Rotatable.h"


Rotatable::Rotatable(float moi):momentOfInertia_(moi), angularAcceleration_(0), angularVelocity_(0), rotation_(0)
{
}


Rotatable::~Rotatable(void)
{
}

void Rotatable::applyTorque(float torque)
{
	this->angularAcceleration_ += torque / this->momentOfInertia_;
}
void Rotatable::applyForce(const sf::Vector2f& force, float distance)
{
	sf::Vector2f arm(distance * cosf(this->rotation_), distance * sinf(this->rotation_));
	float torque = jck::vector::cross(arm, force);
	this->applyTorque(torque);
}

void Rotatable::update(const sf::Time& elapsed)
{

	this->angularVelocity_ = this->angularAcceleration_ * elapsed.asSeconds();

	this->rotation_ += this->angularVelocity_ * elapsed.asSeconds();
}