#ifndef GUILAYER_HPP
#define GUILAYER_HPP

#include <ostream>

namespace grout
{
class GuiLayer
{
public:
    GuiLayer();
};
};


inline std::ostream& operator<<(std::ostream &strm, const grout::GuiLayer &a)
{
    return strm << "GuiLayer" << std::endl;
}

#endif // GUILAYER_HPP
