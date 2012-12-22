#include "UpdateVisitor.hpp"
#include "Transform.hpp"
#include "Renderer.hpp"
#include "PlayerController.hpp"
#include <iostream>

using namespace grout;

UpdateVisitor::UpdateVisitor()
{
}

UpdateVisitor::~UpdateVisitor()
{
}

void UpdateVisitor::visit(PlayerController *playerController)
{
    std::cout << "VISITING PLAYERCONTROLLER" << std::endl;
}

void UpdateVisitor::visit(Transform *transform)
{
    std::cout << "VISITING TRANSFORM" << std::endl;
}

void UpdateVisitor::visit(Renderer *renderer)
{
    std::cout << "VISITING Renderer" << std::endl;
}
