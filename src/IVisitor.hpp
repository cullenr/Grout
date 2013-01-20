#ifndef IVISITOR_H
#define IVISITOR_H

namespace grout
{
class PlayerController;
class Transform;
class Sprite;
class Animation;
class AnimationSequence;
class TilemapLayer;
class Layer;
class LayerChild;
class InputComponent;

struct IVisitor
{
    IVisitor();
    virtual ~IVisitor();

    virtual void visit(PlayerController *) = 0;
    virtual void visit(Transform *) = 0;
    virtual void visit(Sprite *) = 0;
    virtual void visit(Animation *) = 0;
    virtual void visit(AnimationSequence *) = 0;
    virtual void visit(Layer *) = 0;
    virtual void visit(LayerChild *) = 0;
    virtual void visit(InputComponent *) = 0;
};
};
#endif // IVISITOR_H
