#ifndef SCENE_H
    #define SCENE_H

#include "IUpdateable.hpp"
#include <iostream>
#include <list>

class Actor;

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

        void update();
        void render();
        virtual void onUpdate(){};
        void addActor(Actor *actor);
        void removeActor(Actor *actor);
};

#endif
