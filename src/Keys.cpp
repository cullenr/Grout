#include "Keys.hpp"
#include <SFML/Window.hpp>
#include <iostream>

using namespace input;

bool Keys::isKeyPressed(int keyCode)
{
    sf::Keyboard::Key key = (sf::Keyboard::Key)keyCode;
    return sf::Keyboard::isKeyPressed(key);
}

