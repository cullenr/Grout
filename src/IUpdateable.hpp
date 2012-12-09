#ifndef IUPDATEABLE_H
    #define IUPDATEABLE_H

#include "IComponent.hpp"

class IUpdateable// : public IComponent
{
public :
    void update();//cannot be pure virtual as there are collections of these
};

#endif
