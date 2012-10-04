#include "Application.h"
#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

void printVersion()
{
    std::cout << "Version " << GROUT_VERSION_MAJOR << 
        "." << GROUT_VERSION_MINOR << std::endl;
}

int main(int argc, char* argv[]) 
{
    printVersion();

    RenderWindow window(VideoMode(800, 600), "Grout");
    Application app;

    app.create(window);

    while (window.IsOpened())
    {
        app.update(window);
        app.draw(window);
    }

    return EXIT_SUCCESS;
}