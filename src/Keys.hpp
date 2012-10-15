#ifndef KEYS_H
    #define KEYS_H

#include "LuaState.h"
#include <luabind/luabind.hpp>

namespace input
{
	class Keys
	{
	private:
	public:
		Keys(){};
        ~Keys(){};

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

#endif KEYS_H
