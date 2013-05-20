#include "Point.hpp"

using namespace grout::math;

Point& Point::operator+=(const Point &rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;

    return *this;
}

const Point Point::operator+(const Point &rhs) const
{
    return Point(*this) += rhs;
}

Point& Point::operator-=(const Point &rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;

    return *this;
}

const Point Point::operator-(const Point &rhs) const
{
    return Point(*this) -= rhs;
}

Point& Point::operator*=(const Point &rhs)
{
    this->x *= rhs.x;
    this->y *= rhs.y;

    return *this;
}

const Point Point::operator*(const Point &rhs) const
{
    return Point(*this) *= rhs;
}

Point& Point::operator*=(const float &rhs)
{
    this->x *= rhs;
    this->y *= rhs;

    return *this;
}

const Point Point::operator*(const float &rhs) const
{
    return Point(*this) *= rhs;
}
