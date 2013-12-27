#pragma once
#include <SFML\Graphics.hpp>

class Target :
	public sf::Drawable
{
public:
	Target(void);
	~Target(void);
	sf::Vector2f& position(void) { return this->position_; };
	const sf::Vector2f& position(void) const { return this->position_; };
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::RectangleShape image_;
	sf::Vector2f position_;
};

