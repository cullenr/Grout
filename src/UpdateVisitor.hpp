#ifndef UPDATEVISITOR_H
#define UPDATEVISITOR_H

#include "IVisitor.hpp"
#include "RenderController.hpp"
#include <list>

namespace grout
{
class UpdateVisitor : public IVisitor
{
private:
    RenderController &mRenderController;
public:
    UpdateVisitor(RenderController &renderController);
    ~UpdateVisitor();

    void visit(PlayerController *);
    void visit(Transform *);
    void visit(Sprite *);
    void visit(Animation *);
    void visit(AnimationSequence *);
    void visit(Layer *);
    void visit(LayerChild *);
};
};

#endif // UPDATEVISITOR_H
