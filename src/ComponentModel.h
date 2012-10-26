#ifndef COMPONENT_MODEL_H
#define COMPONENT_MODEL_H

#include "LuaState.h"
#include <list>

class IUpdateable;
class IFixedUpdateable;
class IRenderable;
class IComponent;

class ComponentModel {
private:

    /**
     * @brief mUpdateables is a list of IComponent* that have their update methods
     */
    std::list<IUpdateable *> mUpdateables;
    std::list<IFixedUpdateable *> mFixedUpdateables;
    std::list<IRenderable *> mRenderables;

public :
    ComponentModel(){}
    ~ComponentModel(){}

    void registerComponent(IComponent* component);

    static void bindToLua(LuaState &luaState)
    {
        luabind::module(luaState)
        [
            luabind::class_<ComponentModel>("ComponentModel")
        ];
    }
};

#endif // COMPONENT_MODEL_H
