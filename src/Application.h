#ifndef APPLICATION_H
    #define APPLICATION_H
#include "LuaState.h"
#include "IUpdateable.h"
#include "Scene.hpp"
#include "updatemanager.h"
#include <list>
#include <iostream>

namespace sf {
    class RenderWindow;
}

template<typename T>
void bindToLua(LuaState &luaState)
{
    T::bindToLua(luaState);
}

class Application
{
    private:
        UpdateManager mUpdateManager;
        LuaState mLuaState;
        std::list<IUpdateable*> mUpdateables;

        void pollEvents(sf::RenderWindow &window) const;
    public:
        Application(){std::cout << "APPLICATION::CREATE" << std::endl;};
        ~Application(){std::cout << "APPLICATION::DESTROY" << std::endl;};

        void create(sf::RenderWindow &window);
        void update(sf::RenderWindow &window);
        void draw(sf::RenderWindow &window0);

        void setScene(float arg);
};

#endif
