#include "Actor.hpp"
#include <iostream>
#include <string>

using namespace grout;

void Actor::update()
{
    //std::cout << "update actor" << std::endl;
}

void Actor::addComponent(std::string key, IComponent *component)
{
    mComponents.push_back(std::make_pair(&key, component));
}

IComponent* Actor::getComponent(std::string &key)
{
    std::vector<std::pair<std::string *, IComponent *> >::iterator itr;

    for(itr = mComponents.begin(); itr != mComponents.end(); ++itr)
    {
        if(*(itr->first) == key)
            return itr->second;
    }

    return NULL;
}


std::vector<std::pair<std::string *, IComponent *> > Actor::getComponents()
{
    return mComponents;
}
