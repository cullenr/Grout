#ifndef LUA_STATE_H
    #define LUA_STATE_H
#include <lua.hpp>
#include <luabind/luabind.hpp>
#include <iostream>

class LuaState
{
	lua_State *L;
    bool isReleased;

public:
  	LuaState() : L(luaL_newstate())
    {
        luaL_openlibs(L);
        luabind::open(L);
  	}
	
	~LuaState() 
	{
        release();
	}
	
    bool release()
    {
        if(!isReleased)
        {
            lua_close(L);
            std::cout << "DESTROY LUASTATE" << std::endl;

            isReleased = true;
        }
    }

	inline operator lua_State *()
    {
		return L;
	}	
};

#endif
