#include <iostream>
#include "Keys.hpp"

using namespace input;
using namespace std;

void Keys::processEvent(sf::Event &event, LuaBindings *bindings)
{
	if(event.Type == sf::Event::KeyReleased ||
		event.Type == sf::Event::KeyPressed )
	{
		if(event.Type == sf::Event::KeyPressed)
		{			
			cout << "UNIQUE PRESS : " << event.Key.Code << endl;
			bindings->onKeyDown(event.Key.Code);

		}
		else if(event.Type == sf::Event::KeyReleased)
		{
			cout << "UNIQUE RELEASE : " << event.Key.Code << endl;
			bindings->onKeyUp(event.Key.Code);
		}
	}
}