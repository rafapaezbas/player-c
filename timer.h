#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>
#include <iostream>

struct Timer {

	unsigned int startTime;
	unsigned int setupTime;
	bool finished = false;
	//Flag that indicates that this is a timer for waiting
	bool waitingTimer = false;

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

	bool isWaitingTimer(){
		return waitingTimer;
	}

	bool isFinished(){
		return finished;
	}
};

#endif
