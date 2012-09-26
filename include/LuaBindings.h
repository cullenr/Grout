#include <iostream>

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