#ifndef LAYER_HPP
    #define LAYER_HPP

#include "IComponent.hpp"
#include <list>
#include <string>
#include <ostream>

namespace grout
{
class LayerChild;
class Layer : public IComponent
{
public:
    std::list<LayerChild *> children;

    Layer();
    ~Layer();

    void addChild(LayerChild *);//Can we do this automatically using the LayerChild? - for create destroy - yes, but for changing layer on an update we would need to store a flag or somthing...
    void removeChild(LayerChild *);

    void accept(IVisitor *visitor);
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::Layer &a)
{
    return strm << "Layer" << std::endl;
}

#endif // LAYER_HPP
