#ifndef APPLICATION_H
    #define APPLICATION_H
#include "SDL.h"
#include "SDL_main.h"
#include "LuaState.h"
#include "Context.h"
#include "UpdateController.h"
#include "Keys.h"
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
        LuaState mLuaState;
        UpdateController mUpdateController;
        Context mContext;
        bool mRunning;

        void pollEvents();
    public:
        Application()
        {
            mSurface = NULL;

            std::cout << "APPLICATION::CREATE" << std::endl;
        };
        ~Application()
        {
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
