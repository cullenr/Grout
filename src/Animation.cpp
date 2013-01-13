#include "Animation.hpp"
#include "IVisitor.hpp"

using namespace grout;

Animation::~Animation()
{

}

void Animation::accept(IVisitor *visitor)
{
    visitor->visit(this);
}

math::Rectangle* Animation::getRectangle() const
{
    return mSprites[mFrame]->getRectangle();
}

Texture* Animation::getTexture() const
{
    return mSprites[mFrame]->getTexture();
}

Shader* Animation::getShader() const
{
    return mSprites[mFrame]->getShader();
}
