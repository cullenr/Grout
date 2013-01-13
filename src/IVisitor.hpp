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

struct IVisitor
{
    IVisitor();
    virtual ~IVisitor();

    virtual void visit(PlayerController *) = 0;
    virtual void visit(Transform *) = 0;
    virtual void visit(Sprite *) = 0;
    virtual void visit(Animation *) = 0;
    virtual void visit(AnimationSequence *) = 0;
};
};
#endif // IVISITOR_H
