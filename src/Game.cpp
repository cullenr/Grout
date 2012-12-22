#include "Game.hpp"
#include "LuaBindings.hpp"
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

//    std::string script = "actor = Actor()\n"
//            "transform = Transform()\n"
//            "actor:addComponent('myTransform', transform)\n"
//            "renderer = Renderer()\n"
//            "actor:addComponent('myRenderer', renderer)\n"
//            "grout.ctx.scene:addActor(actor)\n";

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
}
