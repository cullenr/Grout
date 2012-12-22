#include "Application.hpp"
#include "config.hpp"
#include <iostream>
#include "SDL.h"

void printVersion()
{
    std::cout << "Version " << GROUT_VERSION_MAJOR <<
        "." << GROUT_VERSION_MINOR << std::endl;
}

int main(int argc, char* args[])
{
    printVersion();

    grout::Application* app = new grout::Application();

    app->create();

    while (app->getIsRunning())
    {
        app->update();
        app->draw();
    }

    delete app;

    return EXIT_SUCCESS;
}
