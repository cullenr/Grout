#ifndef GAME_HPP
    #define GAME_HPP

#include "UpdateVisitor.hpp"
#include "LuaState.hpp"
#include "Context.hpp"
#include <string>

class SDL_Surface;
namespace grout
{
class Game
{
    Context mContext;
    LuaState mLuaState;
    UpdateVisitor mUpdateVisitor;
public:
    Game();
    ~Game();

    void load(std::string);//TODO : ADD SOME SORT OF ARGUMENT THAT ALOWS US TO PASS IN STATE FROM PREVIOUS GAMES OR SAVES
    void update();
    void draw();
};
};

#endif // GAME_HPP
