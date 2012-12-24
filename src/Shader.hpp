#ifndef SHADER_HPP
#define SHADER_HPP

#include "IRenderable.hpp"

namespace grout
{
class Shader : public IRenderable
{
public:
    Shader();
    ~Shader();

    void draw();
};
};

#endif // SHADER_HPP
