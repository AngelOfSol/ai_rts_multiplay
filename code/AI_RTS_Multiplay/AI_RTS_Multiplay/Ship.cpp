#include "Ship.h"


Ship::Ship(void): Movable(2), image_(sf::Vector2f(120, 20)), rotation_(), target_()
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
	float targetAngle = atan2( this->target_.y - this->position_.y, this->target_.x - this->position_.x );
	float currentAngle = this->rotation_ * jck::PI / 180;
	float angleDiff = currentAngle - targetAngle;
	float mag = abs(angleDiff);
	float degrees = jck::PI / 6;
	if(mag > degrees)
	{
//		targetAngle = currentAngle + jck::PI / 6 * mag / angleDiff;
	}
	this->acceleration_.x += 10 * cosf(targetAngle) / this->mass_;
	this->acceleration_.y += 10 * sinf(targetAngle) / this->mass_;
	Movable::update(elapsed);
	if(this->velocity_.x != 0 || this->velocity_.y != 0)
		this->rotation_ = atan2f(this->velocity_.y, this->velocity_.x) * 180.0f / jck::PI;
}

void Ship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	sf::Transform transform;
	transform.translate(this->position_);

	// apply the entity's transform -- combine it with the one that was passed by the caller
    states.transform *= transform; 

	sf::VertexArray line(sf::Lines);
	line.append(sf::Vertex(sf::Vector2f(0, 0)));
	
	float targetAngle = atan2( this->target_.y - this->position_.y, this->target_.x - this->position_.x );
	float currentAngle = this->rotation_ * jck::PI / 180;
	float angleDiff = currentAngle - targetAngle;
	float mag = abs(angleDiff);
	float degrees = jck::PI / 6;
	float correction = degrees * mag / angleDiff;
	if(mag > degrees)
	{
		//targetAngle = currentAngle + degrees * mag / angleDiff;
	}

	line.append(sf::Vertex(sf::Vector2f(10 * cosf(targetAngle), 10 * sinf(targetAngle)), sf::Color::Red));

    // draw the image
	target.draw(line, states);
	states.transform.rotate(this->rotation_);
	states.transform.translate(-60, -10);
	target.draw(this->image_, states);
}