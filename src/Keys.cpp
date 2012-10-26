#include "SDL/SDL_keysym.h"
#include "Keys.h"
#include <iostream>

using namespace input;

uint8_t *Keys::keysDown = NULL;

void Keys::update(uint8_t* newState)
{
    keysDown = newState;
}

bool Keys::isKeyPressed(int keyCode)
{
    if(keyCode > 0 && keyCode < SDLK_LAST && keysDown != NULL)
    {
        return keysDown[keyCode];
    }
    else
    {
        return false;
    }
}
