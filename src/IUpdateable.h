#ifndef IUPDATEABLE_H
#define IUPDATEABLE_H

#include "IComponent.h"

class IUpdateable : public IComponent
{
public :
    virtual void update();//cannot be pure virtual as there are collections of these
};

#endif // IUPDATEABLE_H
