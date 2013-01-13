#ifndef UPDATEVISITOR_H
#define UPDATEVISITOR_H

#include "IVisitor.hpp"
#include <list>

namespace grout
{
class UpdateVisitor : public IVisitor
{
public:
    UpdateVisitor();
    ~UpdateVisitor();

    void visit(PlayerController *);
    void visit(Transform *);
    void visit(Sprite *);
    void visit(Animation *);
    void visit(AnimationSequence *);
    void visit(TilemapLayer *);
};
};

#endif // UPDATEVISITOR_H
