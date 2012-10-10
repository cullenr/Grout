#include "Scene.hpp"
#include "Actor.hpp"

void Scene::update()
{
	list<Actor>::iterator i;

	for(i = actors.begin(); 
		i != actors.end(); 
		++i) 
		i->update();

}

void Scene::addActor(Actor& actor)
{
	actor.push_back(actor);
}