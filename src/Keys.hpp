#ifndef KEYS_H
    #define KEYS_H

#include "LuaState.hpp"
#include <luabind/luabind.hpp>

namespace grout
{
namespace input
{
    class Keys
    {
    protected :

    public :
        static uint8_t *keysDown;
        Keys(){};
        ~Keys(){};

        static void update(uint8_t* newState);

        static bool isKeyPressed(int keyCode);
    };
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::input::Keys &a)
{
    return strm << "PlayerController" << std::endl;
}

#endif
