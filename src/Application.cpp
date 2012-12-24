#include "Application.hpp"
#include "Keys.hpp"
#include "Game.hpp"
#include <iostream>

using namespace grout;

void Application::setup()
{
    int videoFlags;
    const SDL_VideoInfo *videoInfo = NULL;

    if (SDL_Init( SDL_INIT_VIDEO ) < 0)
        throw SDL_GetError();

    videoInfo = SDL_GetVideoInfo();

    if (!videoInfo)
        throw SDL_GetError();

    videoFlags = SDL_OPENGL;
    videoFlags |= SDL_HWPALETTE;

    if ( videoInfo->hw_available )
    {
        videoFlags |= SDL_HWSURFACE;
        videoFlags |= SDL_DOUBLEBUF;
    }
    else
        videoFlags |= SDL_SWSURFACE;

    if ( videoInfo->blit_hw )
        videoFlags |= SDL_HWACCEL;

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw "Could not init SDL";

    if((mSurface = SDL_SetVideoMode(640, 480, 32, videoFlags)) == NULL)
        throw "Could not set video-mode";
}

void Application::createGame()
{
    mGame = new Game();
    mGame->load("assets/level.lua");

    mRunning = true;
}

void Application::update()
{
    pollEvents();

    mGame->update();
    mGame->draw();

    SDL_GL_SwapBuffers();
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
