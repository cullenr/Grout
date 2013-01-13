#ifndef VIEWPORT_HPP
#define VIEWPORT_HPP

#include <iostream>

namespace grout
{
struct Viewport
{
    double left;
    double right;
    double bottom;
    double top;

    Viewport(double left, double right, double bottom, double top)
        : left(left), right(right), bottom(bottom), top(top)
    {

    }
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::Viewport &a)
{
    return strm << "Viewport" << std::endl;
}

#endif // VIEWPORT_HPP
