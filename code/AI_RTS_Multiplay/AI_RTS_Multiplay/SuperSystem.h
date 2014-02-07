#pragma once
#include "system.h"
#include <list>

template <class T>

class SuperSystem :
	public System<T>
{
public:
	SuperSystem(void):System(NULL);
	~SuperSystem(void);
	void start()
	{
		for(auto system = this->systems_.begin(); system != this->systems_.end(); system++)
		{
			(*system)->start();
		}
	}
	void stop()
	{
		for(auto system = this->systems_.begin(); system != this->systems_.end(); system++)
		{
			(*system)->stop();
		}
	};
	void update(T timeStep)	
	{
		for(auto system = this->systems_.begin(); system != this->systems_.end(); system++)
		{
			(*system)->update(timeStep);
		}
	};
	void addSystem(System<T>* system)
	{
		this->systems_.push_back();
	}
private:
	std::list<System<T>*> systems_;
};

