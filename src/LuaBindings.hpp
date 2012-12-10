#include "Actor.hpp"
#include "Scene.hpp"
#include "Context.hpp"
#include "Keys.hpp"
#include "LuaState.hpp"
#include <luabind/luabind.hpp>
#include <luabind/operator.hpp>
#include <vector>

template<typename T>
void bindToLua(LuaState &luaState)
{
    T::bindToLua(luaState);
}

namespace grout
{
struct ActorWrapper : Actor, luabind::wrap_base
{
    ActorWrapper() : Actor()
    {
    }

    static void bindToLua(LuaState &luaState)
    {
        luabind::module(luaState)
        [
            luabind::class_<Actor, ActorWrapper>("Actor")
            .def(luabind::constructor<>())
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
                .property("scene", &Context::getScene)

        ];
    }
};

struct KeyWrapper
{
    static void bindToLua(LuaState &luaState)
    {
        using namespace input;

        luabind::module(luaState)
        [
            luabind::class_<Keys>("Keys")
                .def(luabind::constructor<>())
                .scope
                [
                    luabind::def("isKeyDown", &Keys::isKeyPressed)
                ]
        ];
    }
};

class LuaBindings
{
public :
    static void bind(LuaState &luaState)
    {
        bindToLua<SceneWrapper>(luaState);
        bindToLua<ActorWrapper>(luaState);
        bindToLua<ContextWrapper>(luaState);
        bindToLua<KeyWrapper>(luaState);
    }
};
};
