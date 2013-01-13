#include "Context.hpp"
#include "LuaBindings.hpp"

using namespace grout;

Context::Context()
{
    LuaBindings::bind(luaState);
}
