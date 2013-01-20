#include "InputComponent.hpp"
#include "UpdateVisitor.hpp"
//#include "luabind/detail/call_function.hpp"
#include "luabind/luabind.hpp"

using namespace grout;

InputComponent::InputComponent()
{
}

void InputComponent::accept(IVisitor *visitor)
{
    visitor->visit(this);
}

void UpdateVisitor::visit(InputComponent *inputComponent)
{
    inputComponent->onKeyDown();
}

bool InputComponent::setKeyDownCallback(luabind::object callback)
{
    if(luabind::type(callback) == LUA_TFUNCTION)
    {
        mKeyDownListener = callback;//make a copy as this function may be anonymous
        return true;
    }
    else
    {
        return false;
    }

}

void InputComponent::onKeyDown()
{
    std::cout << "Default onKeyDown" << std::endl;

    if(mKeyDownListener.is_valid())
    {
        luabind::call_function<void>(mKeyDownListener);
    }
}
