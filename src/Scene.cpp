#include "Scene.hpp"
#include "Actor.hpp"
#include <iostream>

void Scene::printHello()
{
    std::cout << "SCENE SAYS HELLO" << std::endl;
}

void Scene::update()
{
    std::cout << "UPDATE SCENE" << std::endl;

    std::list<Actor*>::iterator i;

    for(i = mActors.begin();
        i != mActors.end();
        ++i)
    {
        (*i)->update();
    }

    onUpdate();
}

void Scene::addActor(Actor* actor)
{
    mActors.push_back(actor);
}

void Scene::removeActor(Actor* actor)
{
}
