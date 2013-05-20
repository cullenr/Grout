#include "PhysicsComponent.hpp"
#include "UpdateVisitor.hpp"

using namespace grout;

PhysicsComponent::PhysicsComponent(Transform &transform) : transform(transform)
{
}

PhysicsComponent::~PhysicsComponent()
{
}


void PhysicsComponent::accept(IVisitor *visitor)
{
    visitor->visit(this);
}

void UpdateVisitor::visit(PhysicsComponent *component)
{

}
