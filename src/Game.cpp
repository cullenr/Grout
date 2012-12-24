#include "Game.hpp"
#include "LuaBindings.hpp"
#include "SDL.h"
#include <GL/gl.h>
#include <luabind/object.hpp>
#include <iostream>



#include "Texture.hpp"
#include <string>


using namespace grout;

Game::Game()
{
    mTexture = new Texture("assets/snorlax.png");
}

Game::~Game()
{
}

void Game::load(std::string levelPath)
{
    LuaBindings::bind(mLuaState);

    luabind::object groutTable = luabind::newtable(mLuaState);
    groutTable[ "ctx" ] = &mContext;
    luabind::globals(mLuaState)["grout"] = groutTable;

    if(luaL_dofile(mLuaState, levelPath.c_str()))
    {
        std::cerr << "LUA EXCEPTION!" << std::endl;
        std::cerr << lua_tostring(mLuaState, -1) << std::endl;

        //lua_pop()
    }

    GLint iViewport[4];
    glGetIntegerv( GL_VIEWPORT, iViewport );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(iViewport[0], iViewport[0]+iViewport[2], iViewport[1]+iViewport[3], iViewport[1], -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushAttrib(GL_DEPTH_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
}

void Game::update()
{
    mContext.getScene().visit(mUpdateVisitor);
}

void Game::draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, mTexture->textureId);

    // For Ortho mode, of course
    int X = 0;
    int Y = 0;
    int Width = 80;
    int Height = 80;

    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(X, Y, 0);
        glTexCoord2f(1, 0); glVertex3f(X + Width, Y, 0);
        glTexCoord2f(1, 1); glVertex3f(X + Width, Y + Height, 0);
        glTexCoord2f(0, 1); glVertex3f(X, Y + Height, 0);
    glEnd();
}
