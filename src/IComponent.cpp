#include "IComponent.hpp"
#include <iostream>

using namespace grout;

IComponent::~IComponent()
{

}

void IComponent::accept(IVisitor *visitor)
{
    std::cout << "IComponent accept" << std::endl;
}
