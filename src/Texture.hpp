#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "SDL_image.h"
#include <GL/gl.h>
#include <string>

namespace grout
{
struct Texture
{
    GLuint textureId;

    Texture(std::string);
    ~Texture();
};
};
#endif // TEXTURE_HPP
