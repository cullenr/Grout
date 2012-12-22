#include "Application.hpp"
#include "Keys.hpp"
#include "Game.hpp"
#include <iostream>

using namespace grout;

void Application::setup()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw "Could not init SDL";

    if((mSurface = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL)
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

    mRunning = false;
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
