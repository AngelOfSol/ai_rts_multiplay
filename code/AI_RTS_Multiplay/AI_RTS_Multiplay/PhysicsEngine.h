#pragma once
#include <SFML/System.hpp>
#include <forward_list>
#include "Movable.h"
#include "Force.h"

class PhysicsEngine
{
public:
	PhysicsEngine(void);
	~PhysicsEngine(void);
	void update(const sf::Time&);
	void addForce(Force* force) { this->forces_.push_front(force); };
	void addObject(Movable* object) { this->objects_.push_front(object); };
private:
	std::forward_list<Movable*> objects_;
	std::forward_list<Force*> forces_;
};

