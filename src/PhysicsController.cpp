#include "PhysicsController.hpp"
#include "PhysicsComponent.hpp"
#include "Point.hpp"

using namespace grout;

PhysicsController::PhysicsController()
{
}

void PhysicsController::move(PhysicsComponent &component)// TODO PUT THIS IN A PHYSICS NAMESPACE AND REMOVE IT FROM THE CONTROLLER CLASS!
{
    using namespace math;

    const Point tempPosition = component.transform.position;
    const Point forces = component.persitentForce + component.transientForce;

    component.transform.position += component.transform.previousPosition * forces;
    component.transform.previousPosition = tempPosition;
}
