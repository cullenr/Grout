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
    std::cout << "VISITING TRANSFORM" << std::endl;
}

void UpdateVisitor::visit(Animation *animation)
{
    std::cout << "VISITING Animation" << std::endl;
}

void UpdateVisitor::visit(AnimationSequence *animationSequence)
{
    std::cout << "VISITING AnimationSequence" << std::endl;
}
