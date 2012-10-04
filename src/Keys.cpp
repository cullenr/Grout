#include <iostream>
#include "Keys.hpp"

using namespace input;
using namespace std;

void Keys::processEvent(sf::Event &event)
{
	if(event.Type == sf::Event::KeyReleased ||
		event.Type == sf::Event::KeyPressed )
	{
		if(event.Type == sf::Event::KeyPressed)
		{			
			cout << "UNIQUE PRESS : " << event.Key.Code << endl;

		}
		else if(event.Type == sf::Event::KeyReleased)
		{
			cout << "UNIQUE RELEASE : " << event.Key.Code << endl;
		}
	}
}