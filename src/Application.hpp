#ifndef APPLICATION_H
    #define APPLICATION_H
#include "SDL.h"
#include "Game.hpp"
#include <list>
#include <iostream>

namespace grout
{
class Application
{
    private:
        Game *mGame;
        SDL_Surface *mSurface;
        bool mRunning;

        void pollEvents();
    public:
        Application() : mGame(NULL), mSurface(NULL)
        {
            std::cout << "APPLICATION::CREATE" << std::endl;
        };
        ~Application()
        {
            delete(mGame);

            SDL_FreeSurface(mSurface);
            SDL_Quit();
            std::cout << "APPLICATION::DESTROY" << std::endl;
        };

        void setup();
        void createGame();
        void update();
        void draw();

        const bool& getIsRunning() const
        {
            return mRunning;
        }
};
};

#endif
