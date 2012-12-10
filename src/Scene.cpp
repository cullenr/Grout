#include "Scene.hpp"
#include "Actor.hpp"
#include <iostream>

using namespace grout;

void Scene::update()
{
    std::list<Actor*>::iterator i;

    for(i = mActors.begin();
        i != mActors.end();
        ++i)
    {
        (*i)->update();
    }

    onUpdate();
}

void Scene::render()
{

}

void Scene::addActor(Actor* actor)
{
    std::cout << "add" << std::endl;

    mActors.push_back(actor);
}

void Scene::removeActor(Actor* actor)
{
    throw "NOT IMPLEMENTED";
}
