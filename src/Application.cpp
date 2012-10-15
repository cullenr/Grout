#include "Application.h"
#include "Actor.hpp"
#include "Scene.hpp"
#include "Keys.hpp"
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
    window.setKeyRepeatEnabled(false);

    bindToLua<SceneWrapper>(mLuaState);
    bindToLua<ActorWrapper>(mLuaState);
    bindToLua<input::Keys>(mLuaState);

    mScene = new Scene();

    luabind::globals(mLuaState)["scene"] = mScene;

    luaL_dostring(mLuaState,
        "actor = Actor()\n"
        "function Actor:onUpdate()\n"
            "print(Keys.isKeyDown(2))\n"
        "end\n"
        "scene:addActor(actor)\n"
        "scene:printHello()\n");

    mUpdateManager.addUpdateable(mScene);
}

void Application::update(RenderWindow &window)
{
    pollEvents(window);
    mUpdateManager.update();
}

void Application::draw(RenderWindow &window)
{
    window.clear();

    mScene->render();

    window.display();
}

void Application::pollEvents(sf::RenderWindow &window) const
{
    Event event;

    while(window.pollEvent(event))
    {
        if(event.type == Event::Closed)
        {
            cout << "CLOSE EVENT" << endl;
            window.close();
        }
    }
}
