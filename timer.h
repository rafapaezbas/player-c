#include <SDL2/SDL.h>
#include <iostream>

struct Timer {

	unsigned int startTime;
	unsigned int setupTime;
	bool finished = false;

	Timer(int time){
		start(time);
	}

	void start(unsigned int time){
		setupTime = time;
		startTime = SDL_GetTicks();
	}

	void run(){
		unsigned int passedTime =  SDL_GetTicks() - startTime;
		if(passedTime >= setupTime){
			finished = true;
		}
	}
};
