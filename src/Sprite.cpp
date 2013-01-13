#include "Sprite.hpp"
#include "IVisitor.hpp"
#include "Texture.hpp"

using namespace grout;

Sprite::Sprite(Texture *texture, math::Rectangle *rectangle)
    : mTexture(texture), mRectangle(rectangle)
{
}

Sprite::~Sprite()
{

}

void Sprite::accept(IVisitor *visitor)
{
    visitor->visit(this);
}

Texture* Sprite::getTexture() const
{
    return mTexture;
}

Shader* Sprite::getShader() const
{
    return mShader;
}


math::Rectangle* Sprite::getRectangle() const
{
    return mRectangle;
}

