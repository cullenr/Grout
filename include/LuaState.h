#include "GroutLua.h"
#include <iostream>

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