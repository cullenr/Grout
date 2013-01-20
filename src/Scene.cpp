#include "IComponent.hpp"
#include "Scene.hpp"
#include "Actor.hpp"
#include "Layer.hpp"
#include "LayerChild.hpp"

using namespace grout;

void Scene::visit(IVisitor &visitor)
{
    for(auto actor : actors)
    {
        for(auto componentPair : actor->components)
        {
            componentPair.second->accept(&visitor);
        }
    }

    visitLayerCollection(mPhysicsLayers, visitor);
    visitLayerCollection(mRenderLayers, visitor);
}

void Scene::visitLayerCollection(std::vector<std::pair<std::string, Layer*> > &layers, IVisitor &visitor)
{
    for(auto pair : layers)
    {
        for(LayerChild child : pair.second->children)
        {
            child.accept(&visitor);
        }
    }
}

void Scene::addActor(Actor *actor)
{
    std::cout << "added" << std::endl;

    actors.push_back(actor);
}

void Scene::removeActor(Actor *actor)
{
    actors.remove(actor);
}

void Scene::addRenderLayer(const std::string &name, Layer *layer)
{
    mRenderLayers.emplace_back(name, layer);
}

void Scene::addPhysicsLayer(const std::string &name, Layer *layer)
{
    mPhysicsLayers.emplace_back(name, layer);
}
