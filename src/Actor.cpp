#include "IComponent.hpp"
#include "Actor.hpp"
#include <ostream>
#include <string>

using namespace grout;

void Actor::addComponent(std::string key, IComponent *component)
{
    components.push_back(std::make_pair(&key, component));
}

IComponent* Actor::getComponent(std::string &key)
{
    std::vector<std::pair<std::string *, IComponent *> >::iterator itr;

    for(auto pair : components)
    {
        if(*(pair.first) == key)
            return pair.second;

    }

    return NULL;
}
