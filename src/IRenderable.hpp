#ifndef IRENDERABLE_H
#define IRENDERABLE_H

#include "IComponent.hpp"
#include "LuaState.hpp"
#include "Rectangle.hpp"

namespace grout
{
class IRenderable
{
public :
    math::Rectangle bounds;

    virtual ~IRenderable(){};
    virtual void draw() = 0;

};
};

#endif // IRENDERABLE
