#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <iostream>
#include "Ship.h"
#include "PhysicsEngine.h"
#include "RenderModel.h"
#include "Drag.h"
#include "Current.h"
#include "Target.h"
#include "PositionComponent.h"
#include "VelocityComponent.h"

int main()
{
	
	PositionComponent comp;
	VelocityComponent comp2;
	VelocityComponent comp3;
	std::cout << "PositionComponent: " << comp.type_id << std::endl;
	std::cout << "VelocityComponent: " << comp2.type_id << std::endl;
	std::cout << "VelocityComponent: " << comp3.type_id << std::endl;
	std::string test;
	std::getline(std::cin, test);
	srand(time(NULL));
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(640, 480), "Test", sf::Style::Default, settings);

	PhysicsEngine engine;
	RenderModel model;

	Target currentTarget;
	model.addObject(&currentTarget);

	Drag water(0.3f);
	Current current(sf::Vector2f(rand() % 5 - 2.5, rand() % 5 - 2.5));

	Ship* ship;
	ship = new Ship();
	ship->position().x =  640 / 2;
	ship->position().y =  480 / 2;
	ship->velocity().x =  - 0;
	ship->velocity().y =  - 0;

	float scale = 1;
	engine.addObject(ship);
	model.addObject(ship);

	engine.addForce(&water);
	engine.addForce(&current);

	sf::Clock timer;

	sf::Time minimiumFrameTime = sf::seconds(1.0f / 60.0f);
	int elapsedTotal = 0;
		sf::RenderStates rs;
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
				sf::Vector2f target(event.mouseButton.x - 320, event.mouseButton.y - 240);
				target /= scale;
				target.x += 320;
				target.y += 240;
				currentTarget.position() = target;
				ship->target() = target;
			} if(event.type == sf::Event::MouseWheelMoved)
			{
				rs.transform.translate(320, 240);
				rs.transform.scale(1 + event.mouseWheel.delta * 0.03 , 1+ event.mouseWheel.delta * 0.03 );
				scale *= 1 + event.mouseWheel.delta * 0.03;
				rs.transform.translate(-320, -240);
			}
        }
        // Clear screen
        window.clear(sf::Color(255, 255, 255, 255));
		// Draw stuff
		window.draw(model, rs);
        // Update the window
        window.display();
	}
	return 0;
}
