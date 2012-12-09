#include "ComponentModel.hpp"

#include "IComponent.hpp"
#include "IUpdateable.hpp"
#include "IFixedUpdateable.hpp"
#include "IRenderable.hpp"

void ComponentModel::registerComponent(IComponent* component)
{
    IUpdateable *updateable = dynamic_cast<IUpdateable *>(component);
    if(updateable != NULL)
        mUpdateables.push_back(updateable);

    IFixedUpdateable *fixedUpdateable = dynamic_cast<IFixedUpdateable *>(component);
    if(fixedUpdateable != NULL)
        mFixedUpdateables.push_back(fixedUpdateable);

    IRenderable *renderable = dynamic_cast<IRenderable *>(component);
    if(renderable != NULL)
        mRenderables.push_back(renderable);
}
