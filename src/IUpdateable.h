#ifndef IUPDATEABLE_H
#define IUPDATEABLE_H

class IUpdateable
{
public :
    virtual ~IUpdateable() {};
    virtual void update() = 0;//This notation "= 0" is the pure specifier which means that this is just a prototype.
};

#endif // IUPDATEABLE_H
