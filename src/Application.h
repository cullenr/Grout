#ifndef APPLICATION_H
    #define APPLICATION_H
#include "SDL.h"
#include "SDL_main.h"
#include "LuaState.h"
#include "IUpdateable.h"
#include "Scene.hpp"
#include "UpdateManager.h"
#include "Keys.hpp"
#include <list>
#include <iostream>


template<typename T>
void bindToLua(LuaState &luaState)
{
    T::bindToLua(luaState);
}

class Application
{
    private:
        SDL_Surface *mSurface;
        Scene *mScene;
        LuaState mLuaState;
        UpdateManager mUpdateManager;
        std::list<IUpdateable *> mUpdateables;
        bool mRunning;

        void pollEvents();
    public:
        Application()
        {
            mSurface = NULL;
            mScene = NULL;

            std::cout << "APPLICATION::CREATE" << std::endl;
        };
        ~Application()
        {
            delete mScene;

            SDL_FreeSurface(mSurface);
            SDL_Quit();

            std::cout << "APPLICATION::DESTROY" << std::endl;
        };

        void create();
        void update();
        void draw();

        const bool& getIsRunning() const
        {
            return mRunning;
        }
};

#endif
