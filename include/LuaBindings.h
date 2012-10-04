#ifndef LUA_BINDINGS_H
    #define LUA_BINDINGS_H
class LuaBindings
{
public:
	LuaBindings() 
	{
	}
	
	~LuaBindings()
	{
	}

	int add(lua_State* L, int lhs, int rhs);
	void updateInput(lua_State* L);

};

#endif