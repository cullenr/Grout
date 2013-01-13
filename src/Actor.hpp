#ifndef ACTOR_HPP
    #define ACTOR_HPP

#include "Point.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <utility>

namespace grout
{
class Actor
{
	public:
        std::vector<std::pair<std::string *, IComponent *> > components;

        Actor()
        {
            std::cout << "ACTOR::CONSTRUCT" << std::endl;
        }

        ~Actor()
        {
            std::cout << "ACTOR::DESTRUCT" << std::endl;
        }

        void addComponent(std::string, IComponent *);
        IComponent* getComponent(std::string &);
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::Actor &a)
{
    return strm << "Actor" << std::endl;
}

#endif
