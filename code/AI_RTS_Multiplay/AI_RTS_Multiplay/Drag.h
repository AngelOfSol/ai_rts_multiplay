#pragma once
#include <math.h>
#include "Force.h"

class Drag :
	public Force
{
public:
	Drag(float);
	~Drag(void);
	virtual void actOn(Movable*) const;
private:
	const float dragCoefficent_;
};

