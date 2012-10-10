#include "GroutLua.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

void LuaBindings::onKeyDown(int keyCode)
{
  
}

void LuaBindings::onKeyUp(int keyCode)
{
    //luabind::call_function<int>(mLuaState, "grout.input:triggerKeyUp", keyCode);
}

void LuaBindings::loadFile(const char* path)
{
	if(!luaL_loadfile(mLuaState, path))
        lua_pcall(mLuaState, 0, 0, 0);
    else
        cout << "Could not load file" << endl;
}

void LuaBindings::setLuaPath(const char* path )
{
    lua_getglobal(mLuaState, "package" );
    lua_getfield(mLuaState, -1, "path" );                 // get field "path" from table at top of stack (-1)
    std::string curPath = lua_tostring(mLuaState, -1 );   // grab path string from top of stack
    curPath.append(";" );                                 // add path
    curPath.append(path );
    lua_pop(mLuaState, 1 );                               // get rid of the string on the stack we just pushed on line 5
    lua_pushstring(mLuaState, curPath.c_str() );          // push the new one
    lua_setfield(mLuaState, -2, "path" );                 // set the field "path" in table at -2 with value at top of stack
    lua_pop(mLuaState, 1 );                               // get rid of package table from top of stack

    std::cout << curPath << std::endl;
}

int LuaBindings::add(int lhs, int rhs )
{
	int sum = luabind::call_function<int>(mLuaState, "add", lhs, rhs);
	
	return sum;
}