#include "Actor.hpp"

void Actor::addComponent(IComponent *component)
{
    mComponents.push_back(component);
}
