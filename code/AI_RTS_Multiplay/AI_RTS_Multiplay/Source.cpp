#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <iostream>
#include "Ship.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(640, 480), "Test", sf::Style::Default, settings);


	Ship ship;
	ship.velocity.x = 10;
	ship.velocity.y = 10;

	sf::Clock timer;

	int minimiumFrameTime = sf::seconds(1.0f / 60.0f).asMicroseconds();
	int elapsedTotal = 0;
	while(window.isOpen())
	{
		sf::Time elapsed = timer.restart();
		elapsedTotal += elapsed.asMicroseconds();
		while (elapsedTotal >= minimiumFrameTime)
		{
			std::cout << elapsedTotal << std::endl;
			elapsedTotal %= minimiumFrameTime;
			ship.update(sf::seconds(1.0 / 60.0f));
		}
		
		sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear(sf::Color(255, 255, 255, 255));
		// Draw stuff
		window.draw(ship);
        // Update the window
        window.display();
	}
	return 0;
}
