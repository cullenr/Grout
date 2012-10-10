#include "GroutLua.h"
#include <SFML/Graphics.hpp>

using namespace sf;

namespace input
{
	class Keys
	{
	private:
	public:
		Keys(){};
		~Keys(){};

		void processEvent(Event &event, LuaBindings *luaBindings);
	};
}

