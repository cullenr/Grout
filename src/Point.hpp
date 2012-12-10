#ifndef POINT_H
#define POINT_H

namespace grout
{
namespace math
{
    struct Point
    {
        float x;
        float y;

        Point()
        {
            x = y = 0;
        }
    };
};
};
#endif // POINT_H
