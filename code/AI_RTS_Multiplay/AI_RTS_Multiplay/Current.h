#pragma once
#include <SFML/System.hpp>
#include "force.h"
class Current :
	public Force
{
public:
	Current(const sf::Vector2f&);
	~Current(void);
	virtual void actOn(Movable*) const;
private:
	sf::Vector2f force_;
};

