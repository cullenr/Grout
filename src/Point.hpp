#ifndef POINT_HPP
#define POINT_HPP

#include <ostream>

namespace grout
{
namespace math
{
    struct Point
    {
        float x;
        float y;

        Point() : x(0.f), y(0.f)
        {
        }

        Point(float x, float y) : x(x), y(y)
        {
        }
    };
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::math::Point &a)
{
    return strm << "Point: (" << a.x << ", " << a.y << ')' << std::endl;
}
#endif // POINT_HPP
