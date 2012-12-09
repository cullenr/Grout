#ifndef APPLICATION_H
    #define APPLICATION_H
#include "SDL.h"
//#include "SDL_main.h"
#include "LuaState.hpp"
#include "Context.hpp"
//#include "UpdateController.hpp"
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
        //UpdateController mUpdateController;
        Context *mContext;
        LuaState mLuaState;
        bool mRunning;

        void pollEvents();
    public:
        Application() : mContext(new Context())
        {
            mSurface = NULL;

            std::cout << "APPLICATION::CREATE" << std::endl;
        };
        ~Application()
        {
            SDL_FreeSurface(mSurface);
            SDL_Quit();

            delete mContext;

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
