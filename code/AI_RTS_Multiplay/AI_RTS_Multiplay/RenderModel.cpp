#include "RenderModel.h"


RenderModel::RenderModel(void)
{
}


RenderModel::~RenderModel(void)
{
}

void RenderModel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(auto objectIter = this->objects_.begin(); objectIter != this->objects_.end(); objectIter++)
	{
		target.draw(**objectIter, states);
	}
}