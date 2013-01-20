#ifndef APPLICATION_H
    #define APPLICATION_H
#include "SDL.h"
#include "RenderController.hpp"
#include "UpdateVisitor.hpp"
#include "Game.hpp"
#include <list>
#include <iostream>

namespace grout
{
class Application
{
    private:
        RenderController mRenderController;
        SDL_Surface *mSurface;
        UpdateVisitor mUpdateVisitor;
        Game mGame;
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
