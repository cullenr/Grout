#ifndef IVISITOR_H
#define IVISITOR_H

namespace grout
{
class Animation;
class AnimationSequence;
class InputComponent;
class Layer;
class LayerChild;
class PhysicsComponent;
class Sprite;
class TilemapLayer;
class Transform;


struct IVisitor
{
    IVisitor();
    virtual ~IVisitor();

    virtual void visit(Animation *) = 0;
    virtual void visit(AnimationSequence *) = 0;
    virtual void visit(InputComponent *) = 0;
    virtual void visit(Layer *) = 0;
    virtual void visit(LayerChild *) = 0;
    virtual void visit(PhysicsComponent *) = 0;
    virtual void visit(Sprite *) = 0;
    virtual void visit(Transform *) = 0;
};
};
#endif // IVISITOR_H
