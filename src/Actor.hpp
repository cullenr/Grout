#ifndef ACTOR_H
    #define ACTOR_H

#include "IUpdateable.hpp"
#include "Point.hpp"
#include <iostream>
#include <list>

class Context;

namespace grout
{
class Actor
{
	private:
        std::list<IComponent *> mComponents;

	public:
        Actor()
        {
            std::cout << "ACTOR::CONSTRUCT" << std::endl;
        }

        ~Actor()
        {
            std::cout << "ACTOR::DESTRUCT" << std::endl;
        }

        Actor(const Actor &actor)
        {
            //TODO copy mComponents
            //TODO copy mPoint
        }

        //TODO assignment operator

        virtual void update();
        void addComponent(IComponent *component);
};
};
inline std::ostream& operator<<(std::ostream &strm, const grout::Actor &a)
{
    return strm << "Actor" << std::endl;
}

#endif
