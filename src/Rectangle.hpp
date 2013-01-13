#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.hpp"
#include <string>

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

inline std::ostream& operator<<(std::ostream &strm, const grout::math::Rectangle &a)
{
    return strm << "Rectangle (" << a.topLeft << ", " << a.bottomRight << ')' << std::endl;
}


#endif // RECTANGLE_H
