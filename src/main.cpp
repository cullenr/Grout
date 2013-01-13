#include "Application.hpp"
#include "config.hpp"
#include "SDL.h"
#include <iostream>

void printVersion()
{
    std::cout << "Version " << GROUT_VERSION_MAJOR <<
        "." << GROUT_VERSION_MINOR << std::endl;
}

int main(int argc, char* args[])
{
    printVersion();

    grout::Application* app = new grout::Application();

    app->setup();
    app->createGame();

    while (app->getIsRunning())
    {
        app->update();
    }

    delete app;

    return EXIT_SUCCESS;
}
