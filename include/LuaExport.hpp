#ifndef LUA_EXPORT_H
    #define LUA_EXPORT_H

class LuaExport
{
	private:
		lua_State *mLuaState;
	
	public:	
		LuaExport() : mLuaState(luaL_newstate())
		{
			luaL_openlibs(mLuaState);
			luabind::open(mLuaState);
		}

		~LuaExport()
		{
			lua_close(mLuaState);
		}

		void exportClasses();
};

#endif