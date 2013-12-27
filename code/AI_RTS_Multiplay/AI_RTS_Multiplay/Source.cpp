#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <iostream>
#include "Ship.h"
#include "PhysicsEngine.h"
#include "RenderModel.h"
#include "Drag.h"
#include "Current.h"
#include "Target.h"

int main()
{
	srand(time(NULL));
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(640, 480), "Test", sf::Style::Default, settings);

	PhysicsEngine engine;
	RenderModel model;

	Target currentTarget;
	model.addObject(&currentTarget);

	Drag water(0.5f);
	Current current(sf::Vector2f(rand() % 20 - 10, rand() % 20 - 10));

	Ship* ship;
	ship = new Ship();
	ship->position().x = rand() % 640;
	ship->position().y = rand() % 480;
	ship->velocity().x = rand() % 50 - 25;
	ship->velocity().y = rand() % 50 - 25;

	engine.addObject(ship);
	model.addObject(ship);

	engine.addForce(&water);
	//engine.addForce(&current);

	sf::Clock timer;

	sf::Time minimiumFrameTime = sf::seconds(1.0f / 120.0f);
	int elapsedTotal = 0;
	while(window.isOpen())
	{
		sf::Time elapsed = timer.restart();
		elapsedTotal += elapsed.asMicroseconds();
		while (elapsedTotal >= minimiumFrameTime.asMicroseconds())
		{
			elapsedTotal %= minimiumFrameTime.asMicroseconds();
			engine.update(minimiumFrameTime);
		}
		
		sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
			{
				sf::Vector2f target(event.mouseButton.x, event.mouseButton.y);
				currentTarget.position() = target;
				ship->target() = target;
			}
        }
        // Clear screen
        window.clear(sf::Color(255, 255, 255, 255));
		// Draw stuff
		window.draw(model);
        // Update the window
        window.display();
	}
	return 0;
}
