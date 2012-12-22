#include "Scene.hpp"
#include "Actor.hpp"
#include "IVisitor.hpp"
#include <iostream>

using namespace grout;

void Scene::visit(IVisitor &visitor)
{
    std::list<Actor*>::iterator actorItr;

    for(actorItr = mActors.begin();
        actorItr!= mActors.end();
        ++actorItr)
    {
        std::vector<std::pair<std::string *, IComponent *> > components = (*actorItr)->getComponents();
        std::vector<std::pair<std::string *, IComponent *> >::iterator componentItr;

        for (componentItr = components.begin();
             componentItr != components.end();
             ++componentItr)
        {
            componentItr->second->accept(&visitor);
        }
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
