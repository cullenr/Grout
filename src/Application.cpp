#include "Application.hpp"
#include "Keys.hpp"
#include "Game.hpp"
#include <iostream>

using namespace grout;

Application::Application(): mSurface(NULL), mUpdateVisitor(mRenderController)
{
    std::cout << "APPLICATION::CREATE" << std::endl;
}

Application::~Application()
{
    SDL_FreeSurface(mSurface);
    SDL_Quit();
    std::cout << "APPLICATION::DESTROY" << std::endl;
}

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
    mGame.load("assets/level.lua");

    mRunning = true;
}

void Application::update()
{
    pollEvents();

    mGame.applyVisitor(mUpdateVisitor);

    SDL_GL_SwapBuffers();
}

void Application::draw()
{
    mRenderController.render();
}

void Application::pollEvents()
{
    SDL_Event event;

    input::Keys::resetKeyUpDown();

    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
        case SDL_QUIT :
            mRunning = false;
            break;
        case SDL_KEYDOWN :
            input::Keys::setKeyDown(event.key.keysym.sym);
            break;
        case SDL_KEYUP :
            input::Keys::setKeyUp(event.key.keysym.sym);
            break;
        }
    }
}
