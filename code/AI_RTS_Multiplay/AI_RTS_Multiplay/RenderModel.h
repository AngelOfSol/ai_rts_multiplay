#pragma once
#include <SFML/Graphics.hpp>
#include <forward_list>

class RenderModel : public sf::Drawable
{
public:
	RenderModel(void);
	~RenderModel(void);
	void addObject(sf::Drawable* drawable) { this->objects_.push_front(drawable); };
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	std::forward_list<sf::Drawable*> objects_;
};

