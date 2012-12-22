#ifndef ACTOR_H
    #define ACTOR_H

#include "IUpdateable.hpp"
#include "Point.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <utility>

class Context;

namespace grout
{
class Actor
{
	private:
        std::vector<std::pair<std::string *, IComponent *> > mComponents;

	public:
        Actor()
        {
            std::cout << "ACTOR::CONSTRUCT" << std::endl;
        }

        ~Actor()
        {
            std::cout << "ACTOR::DESTRUCT" << std::endl;
        }

        virtual void update();
        void addComponent(std::string, IComponent *);
        IComponent* getComponent(std::string &);
        std::vector<std::pair<std::string *, IComponent *> > getComponents();

};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::Actor &a)
{
    return strm << "Actor" << std::endl;
}

#endif
