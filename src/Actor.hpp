#ifndef ACTOR_H
    #define ACTOR_H

#include "IUpdateable.hpp"
#include <iostream>
#include <list>

class Context;

class Actor
{
	private:
        Context *mContext;
        std::list<IComponent *> mComponents;

	public:
        Actor(Context *context) : mContext(context)
        {
            std::cout << "ACTOR::CONSTRUCT" << std::endl;
        }

        Actor(const Actor &other) : mContext(other.mContext)
        {
            std::cout << "ACTOR::COPY_CONSTRUCT" << std::endl;
        }

        ~Actor()
        {
            std::cout << "ACTOR::DESTRUCT" << std::endl;
        }

        void addComponent(IComponent *component);
};

inline std::ostream& operator<<(std::ostream &strm, const Actor &a)
{
  return strm << "Acror" << std::endl;
}
#endif
