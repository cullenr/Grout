#include "Actor.hpp"
#include <iostream>

using namespace grout;

void Actor::update()
{
    std::cout << "update actor" << std::endl;
}


void Actor::addComponent(IComponent *component)
{
    mComponents.push_back(component);
}
