#ifndef UPDATE_CONTROLLER_H
#define UPDATE_CONTROLLER_H

#include <list>

class IUpdateable;

class UpdateController
{
private:
    std::list<IUpdateable*> mUpdateables;

public:
    UpdateController(){};
    ~UpdateController(){};

    void addUpdateable(IUpdateable *updateable);
    void update();
};

#endif // UPDATE_CONTROLLER_H
