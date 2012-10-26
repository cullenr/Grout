#include "Actor.h"

void Actor::addComponent(IComponent *component)
{
    mComponents.push_back(component);
}
