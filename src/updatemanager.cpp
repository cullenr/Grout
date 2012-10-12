#include "updatemanager.h"
#include "IUpdateable.h"

void UpdateManager::update()
{
    std::list<IUpdateable*>::iterator i;

    for(i = mUpdateables.begin();
        i != mUpdateables.end();
        ++i)
    {
        (*i)->update();
    }
}

void UpdateManager::addUpdateable(IUpdateable *updateable)
{
    mUpdateables.push_back(updateable);
}
