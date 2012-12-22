#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.hpp"

namespace grout
{
namespace math
{
    struct Rectangle
    {
        Point topLeft;
        Point bottomRight;

        Rectangle()
        {}

        Rectangle(float x, float y, float width, float height) : topLeft(x, y), bottomRight(x + width, y + height)
        {
        }
    };
};
};

#endif // RECTANGLE_H
