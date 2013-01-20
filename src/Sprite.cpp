#include "Sprite.hpp"
#include "UpdateVisitor.hpp"
#include "IVisitor.hpp"

using namespace grout;

Sprite::Sprite(Texture *texture, math::Rectangle *rectangle, Transform *transform)
    : mTexture(texture), mRectangle(rectangle), mTransform(transform)
{
}

Sprite::~Sprite()
{
}

void Sprite::accept(IVisitor *visitor)
{
    visitor->visit(this);
}

void UpdateVisitor::visit(Sprite *sprite)
{
    std::cout << "VISITING Sprite" << std::endl;

    mRenderController.addRenderable(sprite);
}


Transform* Sprite::getTransform() const
{
    return mTransform;
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

