#include "IComponent.hpp"
#include "Scene.hpp"
#include "Actor.hpp"

using namespace grout;

void Scene::visit(IVisitor &visitor)
{
    for(auto actor : actors)
    {
        for(auto componentPair : actor->components)
        {
            componentPair.second->accept(&visitor);
        }
    }
}

void Scene::addActor(Actor *actor)
{
    std::cout << "added" << std::endl;

    actors.push_back(actor);
}

void Scene::removeActor(Actor *actor)
{
    actors.remove(actor);
}
