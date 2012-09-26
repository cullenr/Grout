#include <SFML/Graphics.hpp>
#include <iostream>

class Application
{
	private:
		sf::Sprite *sprite;
		sf::Image image;

		void initLua();
		void pollEvents(sf::RenderWindow &window);

	public:
		Application()
		{
			std::cout << "Application::CREATE" << std::endl;
		}

		~Application();

		void create();
		void update(sf::RenderWindow &window);
		void draw(sf::RenderWindow &window);
};