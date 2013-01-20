#ifndef SHADER_HPP
#define SHADER_HPP
#include <ostream>

namespace grout
{
class Shader
{
public:
    Shader();
    ~Shader();
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::Shader &a)
{
    return strm << "Shader" << std::endl;
}


#endif // SHADER_HPP
