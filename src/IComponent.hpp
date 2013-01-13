#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

#include "LuaState.hpp"
#include <string>

namespace grout
{
    class IVisitor;
    //This class must be defined for the lua bindings to work properly. Objects implementing
    //IComponent must be registered as subclasses of IComponent in the LuaBind bindings. If
    //this is not doen then the application will not recognise IComponents as IComponent.
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

#endif // ICOMPONENT_HPP
