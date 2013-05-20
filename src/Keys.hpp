#ifndef KEYS_H
    #define KEYS_H

#include "LuaState.hpp"
#include <vector>
#include <luabind/luabind.hpp>

namespace grout
{
namespace input
{
class Keys
{
    static std::vector<char> mKeysDownThisTick;//TODO Convert these to structs that include the modifier keys.
    static std::vector<char> mKeysUpThisTick;
public :
    Keys();
    static void resetKeyUpDown();
    static void setKeyDown(char);
    static void setKeyUp(char);

    static const std::vector<char>& getKeysDownThisTick();
    static const std::vector<char>& getKeysUpThisTick();
};
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::input::Keys &a)
{
    return strm << "Keys" << std::endl;
}

#endif
