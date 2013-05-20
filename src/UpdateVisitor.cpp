#include "UpdateVisitor.hpp"
#include "Transform.hpp"
#include <iostream>

using namespace grout;

UpdateVisitor::UpdateVisitor(RenderController &renderController)
    : mRenderController(renderController)
{
}

UpdateVisitor::~UpdateVisitor()
{
}


//TODO : MOVE ALL OF THESE INTO THEIR RESPECTIVE TRANSLATION UNITS

void UpdateVisitor::visit(Transform *transform)
{
}

void UpdateVisitor::visit(Animation *animation)
{
}

void UpdateVisitor::visit(AnimationSequence *animationSequence)
{
}
