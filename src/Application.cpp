#include "Application.h"
#include "Actor.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <luabind/object.hpp>

using namespace std;
using namespace sf;

void Application::setScene(float arg)
{
    cout << "ARG::" << arg << endl;
}

void Application::create(RenderWindow &window)
{
    window.EnableKeyRepeat(false);

    bindToLua<SceneWrapper>(mLuaState);
    bindToLua<ActorWrapper>(mLuaState);

    Scene* scene = new Scene();//TODO : fix leak

    luabind::globals(mLuaState)["scene"] = scene;

    luaL_dostring(mLuaState,
        "actor = Actor()\n"
        "function Actor:onUpdate()\n"
            "print('actor derived update')\n"
        "end\n"
        "scene:addActor(actor)\n"
        "scene:printHello()\n");

    scene->update();
}

void Application::update(RenderWindow &window)
{
    pollEvents(window);
    mUpdateManager.update();
}

void Application::draw(RenderWindow &window)
{
	window.Clear();
    window.Display();
}

void Application::pollEvents(sf::RenderWindow &window) const
{
    Event event;

    while(window.GetEvent(event)) 
    {
        if(event.Type == Event::Closed)
        {
            cout << "CLOSE EVENT" << endl;
            window.Close();    
        }
    }
}
