#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Point.hpp"
#include <string>

namespace grout
{
namespace math
{
    struct Rectangle
    {
        int x;
        int y;
        int width;
        int height;

        Rectangle()
            : x(0), y(0), width(0), height(0)
        {}

        Rectangle(float x, float y, float width, float height)
            : x(x), y(y), width(width), height(height)
        {}
    };
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::math::Rectangle &a)
{
    return strm << "Rectangle (" << a.x << ", " << a.y << ", " << a.width << ", " << a.height << ')' << std::endl;
}


#endif // RECTANGLE_HPP
