#include "Game.hpp"
#include "Viewport.hpp"
#include "LuaBindings.hpp"
#include "SDL.h"
#include "SDL_opengl.h"
#include <luabind/object.hpp>
#include <ostream>

using namespace grout;

Game::Game()
{
}

Game::~Game()
{
}

void Game::load(std::string levelPath)
{
    luabind::object groutTable = luabind::newtable(mContext.luaState);
    groutTable[ "ctx" ] = &mContext;
    luabind::globals(mContext.luaState)["grout"] = groutTable;

//    try
//    {
//        luaL_loadfile(mLuaState, levelPath.c_str());
//        lua_pushcfunction(mLuaState, add_file_and_line);
//        int errfunc = lua_gettop(mLuaState);
//        int error = lua_pcall(mLuaState, 0, 0, errfunc);
//        if(error)
//        {
//            fprintf(stderr, "Error from pcall: \n");
//        }
//    }
//    catch(const luabind::error& the_error)
//    {
//        luabind::object error_msg(luabind::from_stack(the_error.state(), -1));
//        std::cout << error_msg << std::endl;
//    }

    if(luaL_dofile(mContext.luaState, levelPath.c_str()))
    {
        std::cerr << "LUA EXCEPTION!" << std::endl;
        std::cerr << lua_tostring(mContext.luaState, -1) << std::endl;
    }

    GLint iViewport[4];
    glGetIntegerv( GL_VIEWPORT, iViewport );
    Viewport viewport(iViewport[0], iViewport[0]+iViewport[2], iViewport[1]+iViewport[3], iViewport[1]);
//    mViewports.push_back(viewport);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(viewport.left, viewport.right, viewport.bottom, viewport.top, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushAttrib(GL_DEPTH_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
}

void Game::applyVisitor(IVisitor &visitor)
{
    mContext.scene.visit(visitor);
}

//void Game::draw()
//{
//    glClear(GL_COLOR_BUFFER_BIT);

////    glBindTexture(GL_TEXTURE_2D, mTexture->textureId);

////    int x = 0;
////    int y = 0;
////    int width = 64;
////    int height = 64;

////    glBegin(GL_QUADS);
////        glTexCoord2f(0, 0); glVertex3f(x, y, 0);
////        glTexCoord2f(1, 0); glVertex3f(x + width, y, 0);
////        glTexCoord2f(1, 1); glVertex3f(x + width, y + height, 0);
////        glTexCoord2f(0, 1); glVertex3f(x, y + height, 0);
////    glEnd();
//}
