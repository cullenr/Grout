#ifndef CONTEXT_H
    #define CONTEXT_H

#include "Scene.h"
#include "LuaState.h"
#include "ComponentModel.h"

class Context
{
    private :
        Scene* mScene;
        ComponentModel* mComponentModel;

    public :
        Context() :
            mScene(new Scene()),
            mComponentModel(new ComponentModel())
        {}

        ~Context()
        {
            delete mScene;
            delete mComponentModel;
        }

        //----------------------------

       const Scene& getScene() const
       {
           return *mScene;
       }

        const ComponentModel& getComponentModel() const
        {
            return *mComponentModel;
        }

        //----------------------------

        static void bindToLua(LuaState &luaState)
        {
            luabind::module(luaState)
            [
                luabind::class_<Context>("Context")
                    .property("scene", &Context::mScene)
                    .property("ComponentModel", &Context::mComponentModel)
            ];
        }
};

#endif // CONTEXT_H
