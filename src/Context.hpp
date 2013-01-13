#ifndef CONTEXT_HPP
    #define CONTEXT_HPP

#include "LuaState.hpp"
#include "Scene.hpp"

namespace grout
{
struct Context
{
    LuaState luaState;
    Scene scene;
    Context();
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::Context &a)
{
  return strm << "Context" << std::endl;
}

#endif // CONTEXT_HPP
