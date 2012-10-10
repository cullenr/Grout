#ifndef SCENE_H
    #define SCENE_H

#include <list>

class Actor;

using namespace std;

class Scene
{
	private:
		
	public:
		std::list<Actor> actors;

		Scene()
		{

		}

		~Scene()
		{
			
		}

		void update();
		void addActor(Actor& actor)
};

#endif