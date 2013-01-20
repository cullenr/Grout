#ifndef INPUTCOMPONENT_HPP
#define INPUTCOMPONENT_HPP

#include "IComponent.hpp"
#include "luabind/luabind.hpp"

namespace grout
{
class IVisitor;
class InputComponent : public IComponent
{
private:
    luabind::object mKeyDownListener;
public:
    InputComponent();

    bool setKeyDownCallback(luabind::object);//it seems that luabind::objects must be passed by value, otherwise we get compile time errors
    void onKeyDown();
    void accept(IVisitor *);
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::InputComponent &a)
{
    return strm << "InputComponent" << std::endl;
}

#endif // INPUTCOMPONENT_HPP
