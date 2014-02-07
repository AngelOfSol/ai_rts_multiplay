#pragma once

#include <SFML\System.hpp>
#include "Angle.h"

namespace jck
{
	namespace vector
	{

		template <class T>
		T mag(const sf::Vector2<T>& rhs)
		{
			return sqrt(pow(rhs.x, 2) + pow(rhs.y, 2));
		}
		template <class T>
		sf::Vector2<T> normalize(const sf::Vector2<T>& rhs)
		{
			return sf::Vector2<T>(rhs.x / mag(rhs), rhs.y / mag(rhs));
		} 
		template <class T>
		Angle<T> atan(const sf::Vector2<T>& rhs)
		{
			return Angle<T>(atan2(rhs.y, rhs.x));
		}
		
		template <class T>
		T dot(const sf::Vector2<T>& lhs, const sf::Vector2<T>& rhs)
		{
			return lhs.x * rhs.x + lhs.y * rhs.y;
		}

		template <class T>
		T cross(const sf::Vector2<T>& lhs, const sf::Vector2<T>& rhs)
		{
			return lhs.x * rhs.y - lhs.y * rhs.x;
		}
	}
}