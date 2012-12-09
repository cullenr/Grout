#ifndef ACTOR_H
    #define ACTOR_H
#include "Context.h"
#include "IUpdateable.h"
#include "LuaState.h"
#include <luabind/luabind.hpp>
#include <iostream>
#include <list>


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

struct ActorWrapper : Actor, luabind::wrap_base
{
    ActorWrapper(Context *context) : Actor(context)
    {
    }

    static void bindToLua(LuaState &luaState)
    {
        luabind::module(luaState)
        [
            luabind::class_<Actor, ActorWrapper>("Actor")
            .def(luabind::constructor<Context *>())
            .def("addComponent", (void(Actor::*)(IComponent*))&Actor::addComponent)
        ];
    }
};

#endif
