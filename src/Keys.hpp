#ifndef KEYS_H
    #define KEYS_H

#include "LuaState.hpp"
#include <luabind/luabind.hpp>

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

        static void bindToLua(LuaState &luaState)
        {
            luabind::module(luaState)
            [
                luabind::class_<Keys>("Keys")
                    .def(luabind::constructor<>())
                    .scope
                    [
                        luabind::def("isKeyDown", &Keys::isKeyPressed)
                    ]
            ];
        }
	};
};

#endif
