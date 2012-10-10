#ifndef LUA_BINDINGS_H
    #define LUA_BINDINGS_H
#include "GroutLua.h"
#include <luabind/luabind.hpp>

class LuaBindings
{
private:
	lua_State *mLuaState;

public:
	LuaBindings() : mLuaState(luaL_newstate())
	{
		luaL_openlibs(mLuaState);
		luabind::open(mLuaState);
	}

	~LuaBindings()
	{
		lua_close(mLuaState);
	}

	int add(int lhs, int rhs);
	void loadFile(const char* path);
	void setLuaPath(const char* path);
	void onKeyDown(int keyCode);
	void onKeyUp(int keyCode);
};

#endif