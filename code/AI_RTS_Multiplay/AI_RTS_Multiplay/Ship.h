#pragma once
#include <SFML\Graphics.hpp>
#include <math.h>
#include "pi.h"

class Ship : public sf::Drawable
{
public:
	Ship(void);
	~Ship(void);
	void update(const sf::Time&);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Vector2f position;
	sf::Vector2f velocity;
private:
	sf::RectangleShape image;
	float rotation;
};

