#ifndef UPDATEVISITOR_HPP
#define UPDATEVISITOR_HPP

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
    void visit(InputComponent *);
};
};

#endif // UPDATEVISITOR_HPP
