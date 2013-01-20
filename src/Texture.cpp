#include "Texture.hpp"
#include "IVisitor.hpp"
#include <string>
#include <iostream>
//We need this to support GL_BGRA which is defined as an extension on windows,
//on other platforms this exists in GL/gl.h
#if defined(__WIN32__)
    #include <GL/glext.h>
#endif

using namespace grout;

Texture::Texture(std::string file)
{
    SDL_Surface *surface = IMG_Load(file.c_str());

    if(surface == NULL)
        std::cerr << file << " not found" << std::endl;

    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    int bytesPerPixel = surface->format->BytesPerPixel;
    GLenum textureFormat;

    switch(bytesPerPixel)
    {
        case 4 :
            textureFormat = (surface->format->Rmask == 0x000000ff) ?
            GL_RGBA : GL_BGRA;
        break;
        case 3 :
            textureFormat = (surface->format->Rmask == 0x000000ff) ?
            GL_RGB : GL_BGR;
        break;
        default :
            std::cerr << file <<" Bad colour format " << bytesPerPixel << std::endl;
    }

    width = surface->w;
    height = surface->h;

    glTexImage2D( GL_TEXTURE_2D, 0, bytesPerPixel, width, height, 0,
                  textureFormat, GL_UNSIGNED_BYTE, surface->pixels );

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    SDL_FreeSurface(surface);
}

Texture::~Texture()
{
    glDeleteTextures(1, &textureId);
}
