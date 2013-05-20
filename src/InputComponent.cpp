#include "InputComponent.hpp"
#include "Keys.hpp"
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
    const std::vector<char> ints = input::Keys::getKeysDownThisTick();

    if(ints.size() > 0)
    {
        if(mKeyDownListener.is_valid())
        {
            try
            {
                luabind::call_function<void>(mKeyDownListener, CollectionWrapper<std::vector<char> >(ints));
            }
            catch(luabind::error &e)
            {
                std::cerr << "onKeyDown listener error, make sure your arguments are correct" << e.what() << std::endl;
            }
        }
    }
}
