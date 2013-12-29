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
	
	float p = 100 / this->mass_;
	sf::Vector2f fv(this->velocity_.x + this->acceleration_.x, this->velocity_.y + this->acceleration_.y); 
	float magfv = sqrtf(fv.x * fv.x + fv.y * fv.y);

	Angle<float> targetAngle = atan2(this->target_.y - this->position_.y, this->target_.x - this->position_.x);
	Angle<float> currentAngle = this->rotation_ * jck::PI / 180;
	Angle<float> angleDiff = targetAngle - currentAngle;
	Angle<float> mag = abs(angleDiff);
	Angle<float> degrees = jck::PI / 2;
	Angle<float> correction = degrees * mag / angleDiff;
	bool flip = false;
	if(mag > jck::PI)
	{
		flip = true;
	}
	sf::Vector2f propulsion(p * cosf(targetAngle), p * sinf(targetAngle));
	if(mag > degrees)
	{
		targetAngle = currentAngle + degrees * mag / angleDiff * (flip ? -1 : 1);
		propulsion = sf::Vector2f(p * cosf(targetAngle), p * sinf(targetAngle));
	} else
	{
		angleDiff = targetAngle - currentAngle;
		float h = magfv * cosf(angleDiff);
		float k = magfv * sinf(angleDiff);
		if(p * p >= k * k)
		{
			float x = sqrt(p * p - k * k) + h;
			sf::Vector2f targetVelocity(x * cosf(targetAngle), x * sinf(targetAngle));
			sf::Vector2f oldpropulsion = sf::Vector2f(x - h, -k);
			propulsion.x = oldpropulsion.x * cosf(angleDiff) - oldpropulsion.y * sinf(angleDiff);
			propulsion.y = oldpropulsion.x * sinf(angleDiff) + oldpropulsion.y * cosf(angleDiff);
			float magpropulsion = sqrt(propulsion.x * propulsion.x + propulsion.y * propulsion.y);
			if(x < 0)
			{
				propulsion = propulsion;
			}
		}
	}

	this->acceleration_.x += propulsion.x;
	this->acceleration_.y += propulsion.y;
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

	sf::VertexArray line(sf::LinesStrip);
	line.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color::Red));
	
	float p = 100 / this->mass_;
	sf::Vector2f fv(this->velocity_.x + this->acceleration_.x, this->velocity_.y + this->acceleration_.y); 
	float magfv = sqrtf(fv.x * fv.x + fv.y * fv.y);

	Angle<float> targetAngle = atan2(this->target_.y - this->position_.y, this->target_.x - this->position_.x);
	Angle<float> currentAngle = this->rotation_ * jck::PI / 180;
	Angle<float> angleDiff = targetAngle - currentAngle;
	Angle<float> mag = abs(angleDiff);
	Angle<float> degrees = jck::PI / 2;
	Angle<float> correction = degrees * mag / angleDiff;
	sf::Vector2f targetVelocity;
	bool flip = false;
	if(mag > jck::PI)
	{
		flip = true;
	}
	sf::Vector2f propulsion(p * cosf(targetAngle), p * sinf(targetAngle));
	if(mag > degrees)
	{
		targetAngle = currentAngle + degrees * mag / angleDiff * (flip ? -1 : 1);
		propulsion = sf::Vector2f(p * cosf(targetAngle), p * sinf(targetAngle));
	} else
	{
		angleDiff = targetAngle - currentAngle;
		float h = magfv * cosf(angleDiff);
		float k = magfv * sinf(angleDiff);
		if(p * p >= k * k)
		{
			float x = sqrt(p * p - k * k) + h;
			targetVelocity = sf::Vector2f(x * cosf(targetAngle), x * sinf(targetAngle));
			sf::Vector2f oldpropulsion = sf::Vector2f(x - h, -k);
			propulsion.x = oldpropulsion.x * cosf(-angleDiff) - oldpropulsion.y * sinf(-angleDiff);
			propulsion.y = oldpropulsion.x * sinf(-angleDiff) + oldpropulsion.y * cosf(-angleDiff);
			float magpropulsion = sqrt(propulsion.x * propulsion.x + propulsion.y * propulsion.y);
			if(x < 0)
			{
				propulsion = propulsion;
			}
		}

	}
	
	line.append(sf::Vertex(this->velocity_, sf::Color::Red));
	line.append(sf::Vertex(this->velocity_, sf::Color::Green));
	line.append(sf::Vertex(this->velocity_ + propulsion, sf::Color::Green));
	line.append(sf::Vertex(this->velocity_ + propulsion, sf::Color::Black));
	line.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color::Black));
	line.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color::Blue));
	line.append(sf::Vertex(targetVelocity, sf::Color::Blue));

	sf::CircleShape circle(p);
	circle.setOutlineColor(sf::Color::Black);
	circle.setOutlineThickness(2);
	circle.move(this->velocity_);
	circle.move(sf::Vector2f(-p, -p));
    // draw the image
	target.draw(circle, states);
	target.draw(line, states);
	states.transform.rotate(this->rotation_);
	states.transform.translate(-60, -10);
	target.draw(this->image_, states);
}