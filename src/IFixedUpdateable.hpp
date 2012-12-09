#ifndef IFIXED_UPDATEABLE_H
#define IFIXED_UPDATEABLE_H

#include "IComponent.hpp"

class IFixedUpdateable : public IComponent
{
public :
    virtual ~IFixedUpdateable() {};
    virtual void update() = 0;//This notation "= 0" is the pure specifier which means that this is just a prototype.
};

#endif // IFIXED_UPDATEABLE_H
