#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "SDL_image.h"
#include <GL/gl.h>
#include <iostream>
#include <string>


namespace grout
{
struct Texture
{
    GLuint textureId;
    int width;
    int height;

    Texture(std::string);
    ~Texture();
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::Texture &a)
{
    return strm << "Texture " << a.textureId << std::endl;
}

#endif // TEXTURE_HPP
