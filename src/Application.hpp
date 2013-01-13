#ifndef APPLICATION_H
    #define APPLICATION_H
#include "SDL.h"
#include "UpdateVisitor.hpp"
#include "Game.hpp"
#include <list>
#include <iostream>

namespace grout
{
class Application
{
    private:
        UpdateVisitor mUpdateVisitor;
        Game mGame;
        SDL_Surface *mSurface;
        bool mRunning;

        void pollEvents();
    public:
        Application();
        ~Application();

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
