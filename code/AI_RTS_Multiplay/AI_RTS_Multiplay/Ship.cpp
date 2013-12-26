#include "Ship.h"


Ship::Ship(void): image(sf::Vector2f(120, 20)), position(), velocity(), rotation()
{
	this->image.setFillColor(sf::Color(0, 0, 0, 0));
	this->image.setOutlineColor(sf::Color::Black);
	this->image.setOutlineThickness(2);
}


Ship::~Ship(void)
{
}

void Ship::update(const sf::Time& elapsed)
{
	this->velocity *= elapsed.asSeconds();
	this->position += this->velocity;
	this->rotation = atan2f(this->velocity.y, this->velocity.x) * 180.0f / jck::PI;
	this->velocity /= elapsed.asSeconds();
}

void Ship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Transform transform;
	transform.translate(this->position);
	transform.rotate(this->rotation);
	transform.translate(-60, -10);

	// apply the entity's transform -- combine it with the one that was passed by the caller
    states.transform *= transform; 


    // draw the image
	target.draw(this->image, states);
}