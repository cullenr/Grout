#include "IComponent.hpp"
#include "Transform.hpp"
#include "Actor.hpp"
#include "Scene.hpp"
#include "Context.hpp"
#include "Keys.hpp"
#include "LuaState.hpp"
#include "Point.hpp"
#include "Rectangle.hpp"
#include "Texture.hpp"
#include "Shader.hpp"
#include "Sprite.hpp"
#include "Animation.hpp"
#include "AnimationSequence.hpp"
#include "Layer.hpp"
#include "LayerChild.hpp"
#include "InputComponent.hpp"

#include <luabind/iterator_policy.hpp>
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

//TODO WHY ARE THESE NOT PUBLICLY INHERITED
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
            .def("addComponent", &Actor::addComponent)
            .def("getComponent", &Actor::getComponent)
            .def(luabind::tostring(luabind::self))
        ];
    }
};

//TODO WHY ARE THESE NOT PUBLICLY INHERITED
struct SceneWrapper : Scene, luabind::wrap_base
{
    SceneWrapper(): Scene(){}

    static void bindToLua(LuaState &luaState)
    {
        luabind::module(luaState)
        [
            luabind::class_<Scene, SceneWrapper>("Scene")
                .def(luabind::constructor<>())
                .def("addActor", &Scene::addActor)
                .def("removeActor", &Scene::removeActor)
                .def_readwrite("actors", &Scene::actors, luabind::return_stl_iterator)
                .def("addRenderLayer", &Scene::addRenderLayer)
                .def("addPhysicsLayer", &Scene::addPhysicsLayer)
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
            luabind::class_<math::Point>("Point")
                .def(luabind::constructor<>())
                .def(luabind::constructor<float, float>())
                .def(luabind::tostring(luabind::self))
                .def_readwrite("x", &math::Point::x)
                .def_readwrite("y", &math::Point::y),

            luabind::class_<math::Rectangle>("Rectangle")
                .def(luabind::constructor<>())
                .def(luabind::constructor<float, float, float, float>())
                .def(luabind::tostring(luabind::self))
                .def_readwrite("x", &math::Rectangle::x)
                .def_readwrite("y", &math::Rectangle::y)
                .def_readwrite("width", &math::Rectangle::width)
                .def_readwrite("height", &math::Rectangle::height),

            luabind::class_<IComponent>("IComponent")
                .def(luabind::constructor<>())
                .def(luabind::tostring(luabind::self)),

            luabind::class_<LayerChild, IComponent>("LayerChild")
                .def(luabind::constructor<IComponent *>())
                .def(luabind::tostring(luabind::self)),

            luabind::class_<Layer, IComponent>("Layer")
                .def(luabind::constructor<>())
                .def("addChild", &Layer::addChild)
                .def("removeChild", &Layer::removeChild)
                .def(luabind::tostring(luabind::self)),

            luabind::class_<Shader>("Shader")
                .def(luabind::constructor<>())
                .def(luabind::tostring(luabind::self)),

            luabind::class_<Texture>("Texture")
                .def(luabind::constructor<std::string>())
                .def(luabind::tostring(luabind::self))
                .def_readonly("textureId", &Texture::textureId),

            luabind::class_<Transform, IComponent>("Transform")
                .def(luabind::constructor<>())
                .def_readwrite("position", &Transform::position)
                .def(luabind::tostring(luabind::self)),

            luabind::class_<InputComponent, IComponent>("InputComponent")
                .def(luabind::constructor<>())
                .def("setKeyDownCallback", &InputComponent::setKeyDownCallback)
                .def(luabind::tostring(luabind::self)),

            luabind::class_<Sprite, IComponent>("Sprite")
                .def(luabind::constructor<Texture *, math::Rectangle *, Transform *>())
                .def(luabind::tostring(luabind::self)),

            luabind::class_<Context>("Context")
                .def(luabind::constructor<>())
                .def_readonly("scene", &Context::scene)
                .def(luabind::tostring(luabind::self))

        ];

        bindToLua<SceneWrapper>(luaState);
        bindToLua<ActorWrapper>(luaState);
        bindToLua<KeyWrapper>(luaState);
    }
};
};
