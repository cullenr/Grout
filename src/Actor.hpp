#ifndef ACTOR_H
    #define ACTOR_H
#include "IUpdateable.h"
#include "LuaState.h"
#include <luabind/luabind.hpp>
#include <iostream>

class Actor : public IUpdateable
{
	private:

	public:
        Actor(){ std::cout << "ACTOR::CONSTRUCT" << std::endl;};
        Actor(const Actor &other){ std::cout << "ACTOR::COPY_CONSTRUCT" << std::endl;};
        ~Actor(){ std::cout << "ACTOR::DESTRUCT" << std::endl;};

		void update();
        virtual void onUpdate() {};
};

struct ActorWrapper : Actor, luabind::wrap_base
{
    ActorWrapper(): Actor(){}

    virtual void onUpdate()
    {
        call<void>("onUpdate");
    }

    static void defaultOnUpdate(Actor* ptr)
    {
        return ptr->Actor::onUpdate();
    }

    static void bindToLua(LuaState &luaState)
    {
        luabind::module(luaState)
        [
            luabind::class_<Actor, ActorWrapper>("Actor")
                .def(luabind::constructor<>())
                .def("onUpdate", &Actor::onUpdate, &ActorWrapper::defaultOnUpdate)
        ];
    }
};

#endif
