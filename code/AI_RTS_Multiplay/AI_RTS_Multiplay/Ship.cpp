#include "Ship.h"


Ship::Ship(void): Movable(2), image_(sf::Vector2f(120, 20)), Rotatable(60), target_(), rudder_(0.0f)
{
	this->image_.setFillColor(sf::Color(0, 0, 0, 0));
	this->image_.setOutlineColor(sf::Color::Black);
	this->image_.setOutlineThickness(2);
}


Ship::~Ship(void)
{
}

void Ship::update(const sf::Time& elapsed)
{
	this->propulsionMag_ = 20 / this->mass_;
	
	sf::Vector2f fv(this->velocity_.x + this->acceleration_.x, this->velocity_.y + this->acceleration_.y);

	float desiredVelocityMagnitude = jck::vector::mag(this->velocity_) + 1;
	if(desiredVelocityMagnitude > jck::vector::mag(this->target_ - this->position_))
	{
		desiredVelocityMagnitude = 0;
		this->propulsionMag_ = 0;
	}

	this->targetVelocity_= jck::vector::normalize(this->target_ - this->position_) * (desiredVelocityMagnitude);

	sf::Vector2f steering = this->targetVelocity_ - fv;
	steering = jck::vector::normalize(steering);
	
	Angle<float> targetAngle = jck::vector::atan(steering);

	this->rudder_ = targetAngle - this->rotation_;


	Angle<float> degrees = jck::PI / 3;
	if(abs(this->rudder_) > degrees && desiredVelocityMagnitude != 0)
	{
		this->rudder_ = degrees * abs(this->rudder_) / this->rudder_;
	}
	
	steering.x = this->propulsionMag_ * cosf(this->rotation_ + this->rudder_);
	steering.y = this->propulsionMag_ * sinf(this->rotation_ + this->rudder_);
	
	this->lastPropulsion_ = steering;
	this->acceleration_ += steering;
	this->angularAcceleration_ = 0;

	Angle<float> targetRotation = jck::vector::atan(this->targetVelocity_);
	Angle<float> torqueDifference(targetRotation - this->rotation_) ;
	float torque = 10 * 120 * torqueDifference / abs(torqueDifference);

	
	Rotatable::applyTorque(torque);
	// create torque to steer instead of using steering
	Rotatable::update(elapsed);
	Movable::update(elapsed);
	//if(this->velocity_.x != 0 || this->velocity_.y != 0)
	//	this->rotation_ = atan2f(this->velocity_.y, this->velocity_.x);
	// std::cout << (int)jck::vector::mag(this->velocity_) << std::endl;
}

void Ship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	sf::Transform transform;
	transform.translate(this->position_);

	// apply the entity's transform -- combine it with the one that was passed by the caller
    states.transform *= transform; 

	sf::VertexArray line(sf::LinesStrip);
	line.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color::Red));
	line.append(sf::Vertex(this->velocity_, sf::Color::Red));
	line.append(sf::Vertex(this->velocity_, sf::Color::Green));
	line.append(sf::Vertex(this->velocity_ + this->lastPropulsion_, sf::Color::Green));
	line.append(sf::Vertex(this->velocity_ + this->lastPropulsion_, sf::Color::Black));
	line.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color::Black));
	line.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color::Blue));
	line.append(sf::Vertex(this->targetVelocity_, sf::Color::Blue));
	line.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color::Blue));
	line.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color::Magenta));
	line.append(sf::Vertex(sf::Vector2f(100 * cosf(this->rotation_), 100 * sinf(this->rotation_)), sf::Color::Magenta));

    // draw the image
	target.draw(line, states);
	states.transform.rotate(this->rotation_.degrees());
	states.transform.translate(-60, -10);
	target.draw(this->image_, states);
}