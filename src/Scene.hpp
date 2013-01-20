#ifndef SCENE_H
    #define SCENE_H
#include <ostream>
#include <string>
#include <vector>
#include <list>
#include <utility>

namespace grout
{
class Actor;
class IVisitor;
class Layer;

class Scene
{
	public:
        std::list<Actor *> actors;
        std::vector<std::pair<std::string, Layer*> > mRenderLayers;     //TODO should these just be a single layer? and we add and remove using the layer properties
        std::vector<std::pair<std::string, Layer*> > mPhysicsLayers;

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

        void addRenderLayer(const std::string&, Layer*);
        void addPhysicsLayer(const std::string&, Layer*);

    private:
        void visitLayerCollection(std::vector<std::pair<std::string, Layer*> > &, IVisitor &);

};
};

inline std::ostream& operator<<(std::ostream &strm, const grout::Scene &a)
{
    return strm << "Scene" << std::endl;
}

#endif
