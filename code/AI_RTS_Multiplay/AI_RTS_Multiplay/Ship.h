#pragma once
#include <SFML\Graphics.hpp>
#include <math.h>
#include "Movable.h"
#include "pi.h"
#include "Angle.h"
#include <iostream>

class Ship : public sf::Drawable, public Movable
{
public:
	Ship(void);
	~Ship(void);
	void update(const sf::Time&);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Vector2f& target() { return this->target_; };
	const sf::Vector2f& target() const { return this->target_; };
private:
	sf::RectangleShape image_;
	Angle<float> rudder_;
	Angle<float> rotation_;
	sf::Vector2f target_;
	sf::Vector2f getPropulsion(const sf::Time& elapsed);
	sf::Vector2f integral_;
	sf::Vector2f preError_;
	sf::Vector2f lastPropulsion_;
	sf::Vector2f targetVelocity_;
};

