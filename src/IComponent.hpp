#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include "LuaState.hpp"
#include <string>

namespace grout
{
    class IVisitor;
    class IComponent
    {
    public:
        virtual ~IComponent();
        virtual void accept(IVisitor *);
    };
};

inline std::ostream& operator<<(std::ostream &strm, const grout::IComponent &a)
{
    return strm << "IComponent" << std::endl;
}

#endif // ICOMPONENT_H
