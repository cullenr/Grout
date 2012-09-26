#include "GroutLua.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void LuaBindings::updateInput(lua_State* L)
{
	lua_getglobal(L, "__INPUT");
	
	if (!lua_istable(L, -1))
	{
    	std::cout << "Creating __INPUT table" << std::endl;
    	lua_newtable(L);
    	lua_setglobal(L, "__INPUT");
    }
  	else
  		std::cout << "yay! got '__INPUT' table" << std::endl;
}

int LuaBindings::add (lua_State* L, int x, int y )
{
	int sum;
	/* the function name */
	lua_getglobal(L, "add");
	/* the first argument */
	lua_pushnumber(L, x);
	/* the second argument */
	lua_pushnumber(L, y);
	/* call the function with 2 arguments, return 1 result */
	lua_call(L, 2, 1);
	/* get the result */
	sum = (int)lua_tointeger(L, -1);
	lua_pop(L, 1);
	return sum;
}
