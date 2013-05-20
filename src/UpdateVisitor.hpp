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

    void visit(Animation *);
    void visit(AnimationSequence *);
    void visit(InputComponent *);
    void visit(Layer *);
    void visit(LayerChild *);
    void visit(PhysicsComponent *);
    void visit(Sprite *);
    void visit(Transform *);

};
};

#endif // UPDATEVISITOR_HPP
