#include "Commands.h"

struct State {
	std::vector<Command*> commands;
	std::vector<Timer> timers;
	bool wait = false;
	bool end = false;
}; 

