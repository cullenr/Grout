#ifndef APPLICATION_H
    #define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Keys.hpp"

class Application
{
	private:
		void pollEvents(sf::RenderWindow &window);

	public:
		Application()
		{
			std::cout << "Application::CREATE" << std::endl;
		}

		~Application()
		{
			std::cout << "Application::DESTROY" << std::endl;
		}

		void create(sf::RenderWindow &window);
		void update(sf::RenderWindow &window);
		void draw(sf::RenderWindow &window);
		void setScene();
};

#endif