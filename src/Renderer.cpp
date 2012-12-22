#include "Renderer.hpp"
#include "IVisitor.hpp"

using namespace grout;

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::accept(IVisitor *visitor)
{
    visitor->visit(this);
}
