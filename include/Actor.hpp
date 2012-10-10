#ifndef ACTOR_H
    #define ACTOR_H

#include <iostream>

using namespace std;

class Actor
{
	private:

	public:
		Actor(){ cout << "ACTOR::CONSTRUCT" << endl;};
		Actor(const Actor &other){cout << "ACTOR::COPY_CONSTRUCT" << endl;};
		~Actor(){ cout << "ACTOR::DESTRUCT" << endl;};

		void update();
};

#endif