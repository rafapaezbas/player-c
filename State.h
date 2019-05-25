#ifndef STATE_H
#define STATE_H

#include "Commands.h"

struct State {
	std::vector<Command*> commands;
	std::vector<Timer> timers;
	bool wait = false;
	bool end = false;
	void runTimers(){
		for (int i = 0; i < timers.size(); i++)
		{
			Timer* t = &timers.at(i);
			t->run();
			if(t->isFinished()){
				if(t->isWaitingTimer()){
					wait = false;
				}
				timers.erase(timers.begin()+i);
			}
		}
	}
}; 

#endif
