#ifndef UPDATEVISITOR_H
#define UPDATEVISITOR_H

#include "IVisitor.hpp"
#include <list>

namespace grout
{
class Actor;
class Transform;
class Renderer;
class PlayerController;

class UpdateVisitor : public IVisitor
{
public:
    UpdateVisitor();
    ~UpdateVisitor();

    void visit(PlayerController *);
    void visit(Transform *);
    void visit(Renderer *);

};
};

#endif // UPDATEVISITOR_H
