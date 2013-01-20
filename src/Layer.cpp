#include "Layer.hpp"
#include "LayerChild.hpp"
#include "IVisitor.hpp"
#include "UpdateVisitor.hpp"

using namespace grout;

Layer::Layer()
{

}

Layer::~Layer()
{

}

void Layer::addChild(LayerChild *child)
{
    children.push_back(child);
}

void Layer::removeChild(LayerChild *child)
{
    children.remove(child);
}

void Layer::accept(IVisitor *visitor)
{
    visitor->visit(this);
}

void UpdateVisitor::visit(Layer *layer)
{
    std::cout << "VISITING Layer" << std::endl;
//    we do nothing here as the layer children are accessed directly by the scene and updated seperatly
//    for(auto* child : layer->children)
//    {
//        child->accept(this);
//    }
}
