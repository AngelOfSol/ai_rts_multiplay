#pragma once
#include "component.h"
#include <SFML\System.hpp>


class PositionComponent :
	public Component, public sf::Vector2f
{
public:
	PositionComponent(void);
	~PositionComponent(void);
};

