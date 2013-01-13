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
                .def_readwrite("topLeft", &math::Rectangle::topLeft)
                .def_readwrite("bottomRight", &math::Rectangle::bottomRight),

            luabind::class_<IComponent>("IComponent")
                .def(luabind::constructor<>()),

            luabind::class_<Shader>("Shader")
                .def(luabind::constructor<>()),

            luabind::class_<Texture>("Texture")
                .def(luabind::constructor<std::string>())
                .def(luabind::tostring(luabind::self))
                .def_readonly("textureId", &Texture::textureId),

            luabind::class_<Sprite, IComponent>("Sprite")
                .def(luabind::constructor<Texture *, math::Rectangle *>())
                .def(luabind::tostring(luabind::self))
                .property("texture", &Sprite::getTexture)
                .property("rectangle", &Sprite::getRectangle)
                .property("shader", &Sprite::getShader),

            luabind::class_<Transform, IComponent>("Transform")
                .def(luabind::constructor<>())
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
