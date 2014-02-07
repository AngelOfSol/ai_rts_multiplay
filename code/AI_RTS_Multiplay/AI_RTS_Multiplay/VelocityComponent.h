#pragma once
#include "component.h"
class VelocityComponent :
	public Component, public sf::Vector2f
{
public:
	VelocityComponent(void);
	~VelocityComponent(void);
};

