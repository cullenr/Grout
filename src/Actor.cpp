#include "Actor.hpp"
#include <iostream>

void Actor::update()
{
    std::cout << "ACTOR :: UPATE" << std::endl;

    onUpdate();
}

//void Actor::onUpdate()
//{
//    std::cout << "ACTOR :: ONUPATE" << std::endl;
//}
