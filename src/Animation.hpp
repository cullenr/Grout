#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "IRenderable.hpp"
#include "IComponent.hpp"
#include "Sprite.hpp"
#include <vector>

namespace grout
{
class Animation : public IComponent, public IRenderable
{
    std::vector<Sprite *> mSprites;
    unsigned int mFrame;
    unsigned int mRate;
public:
    ~Animation();

    Transform* getTransform() const;
    Texture* getTexture() const;
    math::Rectangle* getRectangle() const;
    Shader* getShader() const;

    void accept(IVisitor *);
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::Animation &a)
{
    return strm << "Animation" << std::endl;
}

#endif // ANIMATION_HPP
