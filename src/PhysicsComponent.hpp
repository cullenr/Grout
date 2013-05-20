#ifndef PHYSICSCOMPONENT_HPP
#define PHYSICSCOMPONENT_HPP

#include "Transform.hpp"
#include "IComponent.hpp"
#include "Point.hpp"

namespace grout
{
class IVisitor;
class PhysicsComponent : public IComponent
{
public:
    Transform &transform;

    math::Point transientForce;
    math::Point persitentForce;

    PhysicsComponent(Transform&);
    virtual ~PhysicsComponent();

    virtual void accept(IVisitor *);
};
};

#endif // PHYSICSCOMPONENT_HPP
