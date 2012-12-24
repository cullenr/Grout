#include "Game.hpp"
#include "LuaBindings.hpp"
#include "SDL.h"
#include <GL/gl.h>
#include <luabind/object.hpp>
#include <iostream>

using namespace grout;

Game::Game()
{
}

Game::~Game()
{
}

void Game::load(std::string levelPath)
{
    LuaBindings::bind(mLuaState);

    luabind::object groutTable = luabind::newtable(mLuaState);
    groutTable[ "ctx" ] = &mContext;
    luabind::globals(mLuaState)["grout"] = groutTable;

    if(luaL_dofile(mLuaState, levelPath.c_str()))
    {
        std::cerr << "LUA EXCEPTION!" << std::endl;
        std::cerr << lua_tostring(mLuaState, -1) << std::endl;

        //lua_pop()
    }
}

void Game::update()
{
    mContext.getScene().visit(mUpdateVisitor);
}

void Game::draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLES);
        glVertex3f( 0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f,-1.0f, 0.0f);
        glVertex3f( 1.0f,-1.0f, 0.0f);
    glEnd();
}
