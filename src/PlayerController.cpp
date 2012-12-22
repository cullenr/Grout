#include "PlayerController.hpp"
#include "Keys.hpp"
#include <iostream>

using namespace grout;

PlayerController::~PlayerController()
{

}

//void PlayerController::accept(Actor *actor, IVisitor visitor)
// {
//      actor->getComponent<Transform>();
//      
// }

//template<class T>
//T Actor::getComponent()
//iterate over components and return the

void PlayerController::accept()
{
    bool up = input::Keys::isKeyPressed(upKey);
    bool down = input::Keys::isKeyPressed(downKey);
    bool left = input::Keys::isKeyPressed(leftKey);
    bool right = input::Keys::isKeyPressed(rightKey);

    if(up && !down)
    {
        std::cout << "UP" << std::endl;
    }
    else if(down && !up)
    {
        std::cout << "DOWN" << std::endl;
    }
    else
    {
        //do nothing
    }

    if(left && !right)
    {
        std::cout << "LEFT" << std::endl;
    }
    else if(right && ! left)
    {
        std::cout << "RIGHT" << std::endl;
    }
    else
    {
        //do nothing
    }
}
