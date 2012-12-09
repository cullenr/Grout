#include "Scene.hpp"
#include <iostream>

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
