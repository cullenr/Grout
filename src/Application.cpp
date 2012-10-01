#include "GroutLua.h"
#include "Application.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>

using namespace std;
using namespace sf;

Application::~Application()
{
	cout << "Application::DESTROY" << endl;
	delete sprite;
}

void Application::create()
{
	initLua();

    if (!image.LoadFromFile("assets/snorlax.png"))
        cout << "Application::CREATE ERROR!" << endl;

    sprite = new Sprite();
    sprite->SetImage(image);
    sprite->SetPosition(200.f, 100.f);
}

void Application::update(RenderWindow &window)
{
    pollEvents(window);
}

void Application::draw(RenderWindow &window)
{
	window.Clear();
    window.Draw(*sprite);
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

void Application::initLua()
{
    LuaState L;

    luaL_openlibs(L);

    if(!luaL_loadfile(L, "assets/test.lua"))
        lua_pcall(L, 0, 0, 0);
    else
        cout << "Could not load file" << endl;

    LuaBindings *luaBindings = new LuaBindings();

    int sum = luaBindings->add(L, 1, 2);

    cout << "sum : " << sum << endl;

    luaBindings->updateInput(L);
    luaBindings->updateInput(L);

    delete luaBindings;
}