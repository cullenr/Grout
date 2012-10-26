#include "Application.h"
#include "Actor.h"
#include "Scene.h"
#include "Keys.h"
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

    //bindToLua<SceneWrapper>(mLuaState);
    bindToLua<ActorWrapper>(mLuaState);
    bindToLua<input::Keys>(mLuaState);

    luabind::globals(mLuaState)["ctx"] = mContext;

    luaL_dostring(mLuaState,
        "actor = Actor()\n"
                  "function Actor:onUpdate()\n"
            "print(Keys.isKeyDown(97))\n"
        "end\n"
        "scene:addActor(actor)\n"
        "scene:printHello()\n"
        );

    mUpdateController.addUpdateable(mContext.getScene());

    mRunning = true;
}

void Application::update()
{
    pollEvents();
    mUpdateController.update();
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
