#ifndef LAYERCHILD_HPP
#define LAYERCHILD_HPP
#include "IComponent.hpp"
#include <ostream>

namespace grout
{
struct LayerChild : public IComponent
{
    IComponent *component;

    LayerChild(IComponent *);
    void accept(IVisitor *visitor);
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::LayerChild &a)
{
    return strm << "LayerChild" << std::endl;
}

#endif // LAYERCHILD_HPP
