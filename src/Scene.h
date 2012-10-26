#ifndef SCENE_H
    #define SCENE_H

#include "IUpdateable.h"
#include "LuaState.h"
//#include "Actor.h"
#include <luabind/luabind.hpp>
#include <iostream>
#include <list>

class Actor;

class Scene : public IUpdateable
{
	private:
        std::list<Actor *> mActors;
	public:
		Scene()
		{
            std::cout << "LEVEL CREATED" << std::endl;
		}

		~Scene()
		{	
            std::cout << "LEVEL DESTROYED" << std::endl;
		}

        void update();
        void render();
        virtual void onUpdate(){};
        void printHello();
        void addActor(Actor *actor);
        void removeActor(Actor *actor);
};

//struct SceneWrapper : Scene, luabind::wrap_base
//{
//    SceneWrapper(): Scene(){}

//    virtual void onUpdate()
//    {
//        call<void>("onUpdate");
//    }

//    static void defaultOnUpdate(Scene* ptr)
//    {
//        return ptr->Scene::onUpdate();
//    }

//    static void bindToLua(LuaState &luaState)
//    {
//        luabind::module(luaState)
//        [
//            luabind::class_<Scene, SceneWrapper>("Scene")
//                .def(luabind::constructor<>())
//                .def("addActor", (void(Scene::*)(Actor*))&Scene::addActor)
//                .def("printHello", &Scene::printHello)
//                .def("onUpdate", &Scene::onUpdate, &SceneWrapper::defaultOnUpdate)
//        ];
//    }
//};

#endif
