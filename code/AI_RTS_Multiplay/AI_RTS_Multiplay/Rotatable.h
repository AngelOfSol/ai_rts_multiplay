#pragma once
#include <SFML\System.hpp>
#include "Angle.h"
#include "VectorExtensions.h"
class Rotatable
{
public:
	Rotatable(float);
	~Rotatable(void);
	virtual void update(const sf::Time&);
	Angle<float>& rotation(void) { return this->rotation_; };
	const Angle<float>& rotation(void) const { return this->rotation_; };
	Angle<float>& angularVelocity(void) { return this->angularVelocity_; };
	const Angle<float>& angularVelocity(void) const { return this->angularVelocity_; };
	Angle<float>& angularAcceleration(void) { return this->angularAcceleration_; };
	const Angle<float>& angularAcceleration(void) const { return this->angularAcceleration_; };
	void applyTorque(float);
	void applyForce(const sf::Vector2f&, float);
protected:
	Angle<float> rotation_;
	Angle<float> angularVelocity_;
	Angle<float> angularAcceleration_;
	float momentOfInertia_;
};

