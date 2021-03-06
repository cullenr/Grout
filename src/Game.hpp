#ifndef GAME_HPP
    #define GAME_HPP

#include "Context.hpp"
#include <string>
#include <list>
#include <vector>
#include <utility>

class SDL_Surface;
namespace grout
{
class Layer;
class Game
{
    Context mContext;

public:
    Game();
    ~Game();

    void load(std::string);//TODO : ADD SOME SORT OF ARGUMENT THAT ALOWS US TO PASS IN STATE FROM PREVIOUS GAMES OR SAVES?
    void applyVisitor(IVisitor& visitor);
};
};

#endif // GAME_HPP
