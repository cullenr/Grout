#ifndef CONTEXT_H
    #define CONTEXT_H

#include "Scene.hpp"
#include "ComponentModel.hpp"


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

#endif
