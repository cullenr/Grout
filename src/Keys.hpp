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
    std::vector<int> mKeysDownThisTick;//TODO Convert these to structs that include the modifier keys.
    std::vector<int> mKeysUpThisTick;
public :
    Keys();
    void resetKeyUpDown();
    void setKeyDown(int);
    void setKeyUp(int);

    const std::vector<int>& getKeysDownThisTick() const;
    const std::vector<int>& getKeysUpThisTick() const;
};
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::input::Keys &a)
{
    return strm << "Keys" << std::endl;
}

#endif
