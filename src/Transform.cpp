#include "Transform.hpp"
#include "IVisitor.hpp"
#include <iostream>

using namespace grout;

Transform::Transform()
{
}

Transform::~Transform()
{
}

void Transform::accept(IVisitor *visitor)
{
    visitor->visit(this);
}
