#include <iostream>
#include "Keys.hpp"

using namespace input;
using namespace std;

void Keys::processEvent(sf::Event &event)
{
    if(event.type == sf::Event::KeyReleased ||
        event.type == sf::Event::KeyPressed )
	{
        if(event.type == sf::Event::KeyPressed)
		{			
            cout << "UNIQUE PRESS : " << event.key.code << endl;
		}
        else if(event.type == sf::Event::KeyReleased)
		{
            cout << "UNIQUE RELEASE : " << event.key.code << endl;
		}
	}
}
