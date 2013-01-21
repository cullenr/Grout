#include "InputComponent.hpp"
#include "UpdateVisitor.hpp"
#include "CollectionWrapper.hpp"
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

    std::vector<int> ints = {1, 2, 3};

    if(mKeyDownListener.is_valid())
    {
        try
        {
//            luabind::call_function<void>(mKeyDownListener, 12);
            luabind::call_function<void>(mKeyDownListener, new CollectionWrapper<std::vector<int> >(ints));
        }
        catch(luabind::error &e)
        {
            std::cerr << "onKeyDown listener error, make sure your arguments are correct" << e.what() << std::endl;
        }
    }
}
