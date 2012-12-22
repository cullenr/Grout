#ifndef IVISITOR_H
#define IVISITOR_H

namespace grout
{
class PlayerController;
class Transform;
class Renderer;

struct IVisitor
{
    IVisitor();
    virtual ~IVisitor();

    virtual void visit(PlayerController *) = 0;
    virtual void visit(Transform *) = 0;
    virtual void visit(Renderer *) = 0;
};
};
#endif // IVISITOR_H
