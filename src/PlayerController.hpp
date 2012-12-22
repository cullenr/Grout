#ifndef PLAYERCONTROLLER_HPP
#define PLAYERCONTROLLER_HPP

#include "IComponent.hpp"

namespace grout
{
class PlayerController : public IComponent
{
    public:
        int upKey;
        int downKey;
        int leftKey;
        int rightKey;
        int jumpKey;

        PlayerController(){};
        ~PlayerController();

        void accept();
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::PlayerController &a)
{
    return strm << "PlayerController" << std::endl;
}


#endif // PLAYERCONTROLLER_HPP
