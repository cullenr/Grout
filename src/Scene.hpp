#ifndef SCENE_H
    #define SCENE_H
#include "IUpdateable.hpp"
#include <iostream>
#include <list>


namespace grout
{
class Actor;
class IVisitor;

class Scene : public IUpdateable
{
	private:
        std::list<Actor *> mActors;
	public:
		Scene()
		{
            std::cout << "SCENE CREATED" << std::endl;
		}

		~Scene()
		{	
            std::cout << "SCENE DESTROYED" << std::endl;
		}

        void visit(IVisitor &);
        void render();
        virtual void onUpdate(){};
        void addActor(Actor *);
        void removeActor(Actor *);
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::Scene &a)
{
  return strm << "Scene" << std::endl;
}

#endif
