#pragma once
#include <SFML\System.hpp>

class Movable
{
public:
	Movable(float);
	~Movable(void);
	virtual void update(const sf::Time&);
	const float& mass(void) const { return this->mass_; };
	sf::Vector2f& position(void) { return this->position_; };
	const sf::Vector2f& position(void) const { return this->position_; };
	sf::Vector2f& velocity(void) { return this->velocity_; };
	const sf::Vector2f& velocity(void) const { return this->velocity_; };
	sf::Vector2f& acceleration(void) { return this->acceleration_; };
	const sf::Vector2f& acceleration(void) const { return this->acceleration_; };
	void applyForce(const sf::Vector2f&);
protected:
	float mass_;
	sf::Vector2f position_;
	sf::Vector2f velocity_;
	sf::Vector2f acceleration_;
private:
	void roundOff(void);
};

