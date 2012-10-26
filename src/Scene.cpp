#include "Scene.h"
#include "Actor.h"
#include <iostream>

void Scene::printHello()
{
    std::cout << "SCENE SAYS HELLO" << std::endl;
}

void Scene::update()
{
    onUpdate();
}

void Scene::render()
{
    //std::cout << "SCENE::RENDER" << std::endl;
}

void Scene::addActor(Actor* actor)
{
    mActors.push_back(actor);
}

void Scene::removeActor(Actor* actor)
{
    throw "NOT IMPLEMENTED";
}
