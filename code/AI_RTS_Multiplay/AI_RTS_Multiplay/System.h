#pragma once

#include "EntityEngine.h"

template <class T>
class System
{
public:
	System(EntityEngine* engine):entitiesList_(engine)
	{
	};
	virtual ~System(void);
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void update(T timeStep) = 0;
protected:
	EntityEngine* entitiesList_;
};

