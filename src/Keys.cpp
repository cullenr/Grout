#include "SDL/SDL_keysym.h"
#include "Keys.hpp"
#include <iostream>

using namespace grout::input;

std::vector<char> Keys::mKeysDownThisTick;
std::vector<char> Keys::mKeysUpThisTick;

Keys::Keys()
{
    Keys::mKeysDownThisTick.reserve(10);
    Keys::mKeysUpThisTick.reserve(10);
}

void Keys::resetKeyUpDown()
{
    Keys::mKeysDownThisTick.clear();
    Keys::mKeysUpThisTick.clear();
}

void Keys::setKeyDown(char key)
{
    Keys::mKeysDownThisTick.push_back(key);
}

void Keys::setKeyUp(char key)
{
    Keys::mKeysUpThisTick.push_back(key);
}

const std::vector<char>& Keys::getKeysDownThisTick()
{
    return Keys::mKeysDownThisTick;
}

const std::vector<char>& Keys::getKeysUpThisTick()
{
    return Keys::mKeysUpThisTick;
}
