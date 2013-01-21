#include "SDL/SDL_keysym.h"
#include "Keys.hpp"
#include <iostream>

using namespace grout::input;

Keys::Keys()
{
    mKeysDownThisTick.reserve(10);
    mKeysUpThisTick.reserve(10);
}

void Keys::resetKeyUpDown()
{
    mKeysDownThisTick.clear();
    mKeysUpThisTick.clear();
}


void Keys::setKeyDown(int key)
{
    mKeysDownThisTick.push_back(key);
}

void Keys::setKeyUp(int key)
{
    mKeysUpThisTick.push_back(key);
}


const std::vector<int>& Keys::getKeysDownThisTick() const
{
    return mKeysDownThisTick;
}

const std::vector<int>& Keys::getKeysUpThisTick() const
{
    return mKeysUpThisTick;
}
