#include "LayerChild.hpp"
#include "IVisitor.hpp"
#include "UpdateVisitor.hpp"

using namespace grout;

LayerChild::LayerChild(IComponent *component) : component(component)
{

}

void LayerChild::accept(IVisitor *visitor)
{
    visitor->visit(this);
}

void UpdateVisitor::visit(LayerChild *layerChild)
{
    std::cout << "VISITING LayerChild" << std::endl;
    layerChild->component->accept(this);
}
