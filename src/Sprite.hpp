#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "IComponent.hpp"
#include "IRenderable.hpp"
#include <ostream>

namespace grout
{
class Sprite : public IComponent, public IRenderable
{
    Transform *mTransform;
    Texture *mTexture;
    math::Rectangle *mRectangle;
    Shader *mShader;

public :
    Sprite(Texture *texture, math::Rectangle *rectangle, Transform *transform);
    ~Sprite();

    void accept(IVisitor *visitor);

    Transform* getTransform() const;
    Texture* getTexture() const;
    math::Rectangle* getRectangle() const;
    Shader* getShader() const;
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::Sprite &a)
{
    return strm << "Sprite" << std::endl;
}

#endif // SPRITE_HPP
