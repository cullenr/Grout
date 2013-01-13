#ifndef SCENE_H
    #define SCENE_H
#include <ostream>
#include <list>

namespace grout
{
class Actor;
class IVisitor;

class Scene
{
	public:
        std::list<Actor *> actors;

        Scene()
		{
            std::cout << "SCENE CREATED" << std::endl;
		}

		~Scene()
		{	
            std::cout << "SCENE DESTROYED" << std::endl;
		}

        void visit(IVisitor &);
        void addActor(Actor *);
        void removeActor(Actor *);
};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::Scene &a)
{
    return strm << "Scene" << std::endl;
}

#endif
