#ifndef APPLICATION_H
    #define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Keys.hpp"

class Application
{
	private:
		sf::Sprite *sprite;
		sf::Image image;

		input::Keys *keys;

		void initLua();
		void pollEvents(sf::RenderWindow &window);

	public:
		Application() : keys(new input::Keys())
		{
			std::cout << "Application::CREATE" << std::endl;
		}

		~Application()
		{
			std::cout << "Application::DESTROY" << std::endl;
			delete sprite;
			delete keys;
		}

		void create(sf::RenderWindow &window);
		void update(sf::RenderWindow &window);
		void draw(sf::RenderWindow &window);
};

#endif