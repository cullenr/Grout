#ifndef CONTEXT_H
    #define CONTEXT_H

#include "Scene.hpp"
#include "ComponentModel.hpp"

namespace grout
{
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

        Scene& getScene() const
        {
           return *mScene;
        }

        ComponentModel& getComponentModel() const
        {
            return *mComponentModel;
        }
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::Context &a)
{
  return strm << "Context" << std::endl;
}

#endif
