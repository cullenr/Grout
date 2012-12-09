#include "UpdateController.h"
#include "IUpdateable.h"

void UpdateController::update()
{
    std::list<IUpdateable*>::iterator i;

    for(i = mUpdateables.begin();
        i != mUpdateables.end();
        ++i)
    {
        //(*i)->update();
    }
}

void UpdateController::addUpdateable(IUpdateable *updateable)
{
    mUpdateables.push_back(updateable);
}
