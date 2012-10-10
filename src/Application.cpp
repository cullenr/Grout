#include "GroutLua.h"
#include "Application.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include <luabind/luabind.hpp>

using namespace std;
using namespace sf;

void Application::create(RenderWindow &window)
{
    window.EnableKeyRepeat(false);
}

void Application::update(RenderWindow &window)
{
    pollEvents(window);
    mScene.update();
}

void Application::draw(RenderWindow &window)
{
	window.Clear();
    window.Display();
}

void Application::pollEvents(sf::RenderWindow &window)
{
    Event event;

    while(window.GetEvent(event)) 
    {
        if(event.Type == Event::Closed)
            window.Close();
    }
}