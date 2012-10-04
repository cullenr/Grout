#ifndef LUA_STATE_H
    #define LUA_STATE_H

#include "GroutLua.h"

class LuaState
{
	lua_State *L;

public:
  	LuaState() : L(luaL_newstate())
  	{
  	}
	
	~LuaState() 
	{
		lua_close(L);
	}
	
	inline operator lua_State *()
	{
		return L;
	}	
};

#endif