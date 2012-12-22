#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "IComponent.hpp"

namespace grout
{
class Transform : public IComponent
{   
public:
    Transform();
    ~Transform();

    void accept(IVisitor *);
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::Transform &a)
{
    return strm << "Tranform" << std::endl;
}


#endif // TRANSFORM_H
