#ifndef CONTEXT_H
    #define CONTEXT_H

#include "Scene.h"
#include "Scene.h"
#include "LuaState.h"
#include "ComponentModel.h"
#include "luabind/operator.hpp"

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

        const Scene& getScene() const
        {
           return *mScene;
        }

        const ComponentModel& getComponentModel() const
        {
            return *mComponentModel;
        }
};

inline std::ostream& operator<<(std::ostream &strm, const Context &a)
{
  return strm << "Context" << std::endl;
}

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

#endif // CONTEXT_H
