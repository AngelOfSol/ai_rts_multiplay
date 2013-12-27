#pragma once
#include <SFML\System.hpp>
#include "Movable.h"

class Force
{
public:
	Force(void);
	~Force(void);
	virtual void actOn(Movable*) const = 0;
private:
};

