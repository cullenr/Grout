#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "IComponent.hpp"

namespace grout
{
class IVisitor;
class Renderer : public IComponent
{
public:
    Renderer();
    ~Renderer();

    void accept(IVisitor *);
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::Renderer &a)
{
    return strm << "Renderer" << std::endl;
}

#endif // RENDERER_HPP
