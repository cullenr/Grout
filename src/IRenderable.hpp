#ifndef IRENDERABLE_HPP
#define IRENDERABLE_HPP

namespace grout
{
namespace math
{
    class Rectangle;
}
class Shader;
class Texture;
class Transform;

struct IRenderable
{
    virtual ~IRenderable(){};

    virtual Texture* getTexture() const = 0;
    virtual math::Rectangle* getRectangle() const = 0;
    virtual Shader* getShader() const = 0;
    virtual Transform* getTransform() const = 0;
};
};

#endif // IRENDERABLEPP
