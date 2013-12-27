#include "Target.h"


Target::Target(void): image_(sf::RectangleShape(sf::Vector2f(20, 20)))
{
	this->image_.setFillColor(sf::Color(0, 0, 0, 0));
	this->image_.setOutlineColor(sf::Color::Black);
	this->image_.setOutlineThickness(2);
}


Target::~Target(void)
{
}

void Target::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	sf::Transform transform;
	transform.translate(this->position_);
	transform.translate(-10, -10);

	// apply the entity's transform -- combine it with the one that was passed by the caller
    states.transform *= transform; 


    // draw the image
	target.draw(this->image_, states);
}