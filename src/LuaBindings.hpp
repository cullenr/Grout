#include "Actor.hpp"
#include "Scene.hpp"
#include "Context.hpp"
#include "LuaState.hpp"
#include <luabind/luabind.hpp>
#include <luabind/operator.hpp>

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

struct SceneWrapper : Scene, luabind::wrap_base
{
    SceneWrapper(): Scene(){}

    virtual void onUpdate()
    {
        call<void>("onUpdate");
    }

    static void defaultOnUpdate(Scene* ptr)
    {
        return ptr->Scene::onUpdate();
    }

    static void bindToLua(LuaState &luaState)
    {
        luabind::module(luaState)
        [
            luabind::class_<Scene, SceneWrapper>("Scene")
                .def(luabind::constructor<>())
                .def("addActor", (void(Scene::*)(Actor*))&Scene::addActor)
                .def("onUpdate", &Scene::onUpdate, &SceneWrapper::defaultOnUpdate)
        ];
    }
};

struct ContextWrapper : Context, luabind::wrap_base
{
    ContextWrapper() : Context()
    {
    }

    static void bindToLua(LuaState &luaState)
    {
        luabind::module(luaState)
        [
            luabind::class_<Context, ContextWrapper>("Context")
                .def(luabind::constructor<>())
                .def(luabind::tostring(luabind::self))

        ];
    }
};
