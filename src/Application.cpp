#include "Application.hpp"
#include "Actor.hpp"
#include "Scene.hpp"
#include "Keys.hpp"
#include "LuaBindings.hpp"
#include "SDL.h"
#include <iostream>
#include <luabind/object.hpp>

using namespace std;

void Application::create()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw "Could not init SDL";

    if((mSurface = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL)
        throw "Could not set video-mode";

    LuaBindings::bind(mLuaState);

    luaL_dostring(mLuaState, "print('touch me tender')");

    //TODO : This is a leak, I think i read it causes a crash when we try to destroy the objects.
    //TODO : Read this and work out a solution. http://sylefeb.blogspot.ca/2010/08/luabind-global-tables-of-classes.html
    //luabind::globals(mLuaState)["ctx"] = mContext;

    {
        luabind::object groutTable = luabind::newtable(mLuaState);
        groutTable[ "ctx" ] = mContext;

        luabind::globals(mLuaState)["grout"] = groutTable;
    }

    string script = "print(grout.ctx)\n";

    if(luaL_dostring(mLuaState, script.c_str()))
    {
        cerr << "LUA EXCEPTION!" << endl;
        cerr << lua_tostring(mLuaState, -1) << endl;

        //lua_pop()
    }

    //mUpdateController.addUpdateable(mContext.getScene());

    mRunning = true;
}

void Application::update()
{
    pollEvents();
//    mUpdateController.update();
}

void Application::draw()
{

}

void Application::pollEvents()
{
    bool updateKeys = false;
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
        case SDL_QUIT :
            mRunning = false;
            break;
        case SDL_KEYDOWN :
        case SDL_KEYUP :
            updateKeys = true;
            break;
        }
    }

    if(updateKeys)
    {
        uint8_t *keyboardState = SDL_GetKeyState(NULL);

        input::Keys::update(keyboardState);
    }
}
