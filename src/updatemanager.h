#ifndef UPDATEMANAGER_H
#define UPDATEMANAGER_H

#include <list>

class IUpdateable;

class UpdateManager
{
private:
    std::list<IUpdateable*> mUpdateables;

public:
    UpdateManager(){};
    ~UpdateManager(){};

    void addUpdateable(IUpdateable *updateable);
    void update();
};

#endif // UPDATEMANAGER_H
