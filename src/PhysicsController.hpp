#ifndef PHYSICSCONTROLLER_HPP
#define PHYSICSCONTROLLER_HPP

namespace grout
{
class PhysicsComponent;
class PhysicsController
{
public:
    PhysicsController();
    void move(PhysicsComponent &);
    void collide(PhysicsComponent &, PhysicsComponent &);
};
};

#endif // PHYSICSCONTROLLER_HPP
