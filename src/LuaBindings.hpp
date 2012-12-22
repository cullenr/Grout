#include "IComponent.hpp"
#include "Transform.hpp"
#include "Renderer.hpp"
#include "Actor.hpp"
#include "Scene.hpp"
#include "Context.hpp"
#include "Keys.hpp"
#include "LuaState.hpp"
#include "Point.hpp"
#include "Rectangle.hpp"
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
            .def("addComponent", (void(Actor::*)(std::string, IComponent*))&Actor::addComponent)
            .def("getComponent", &Actor::getComponent)
            .def(luabind::tostring(luabind::self))
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
                .def(luabind::tostring(luabind::self))
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
                .def(luabind::tostring(luabind::self))
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
        luabind::module(luaState)
        [
            luabind::class_<IComponent>("IComponent")
                .def(luabind::constructor<>())
                .def("accept", &IComponent::accept),

            luabind::class_<Transform, IComponent>("Transform")
                .def(luabind::constructor<>())
                .def(luabind::tostring(luabind::self))
                .def("accept", &Transform::accept),

            luabind::class_<Renderer, IComponent>("Renderer")
                .def(luabind::constructor<>())
                .def(luabind::tostring(luabind::self))
                .def("accept", &Renderer::accept),

            luabind::class_<Context>("Context")
                .def(luabind::constructor<>())
                .def(luabind::tostring(luabind::self))
                .property("scene", &Context::getScene),

            luabind::class_<math::Point>("Point")
                .def(luabind::constructor<>())
                .def(luabind::constructor<float, float>())
                .def(luabind::tostring(luabind::self))
                .property("x", &math::Point::x)
                .property("y", &math::Point::y)


        ];

        bindToLua<SceneWrapper>(luaState);
        bindToLua<ActorWrapper>(luaState);
        bindToLua<KeyWrapper>(luaState);
    }
};
};
