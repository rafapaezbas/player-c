#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include "audioUtil.h"

#include "timer.h"

struct Command {
	virtual void execute(){};
};

struct PlayCommand : Command {
	std::string file;
	bool* deviceIsOpen;
	int channel;

	PlayCommand(std::string file_, bool* deviceIsOpen_,int channel_){
		file = file_;
		deviceIsOpen = deviceIsOpen_;
		channel = channel_;
	}

	void execute() override{
		audioutil_pause(channel);
		cleanChunk(channel);
		loadWavFile(file,channel,deviceIsOpen);
		play(channel);
		std::cout << "Playing: " + file << std::endl;
	}
};

struct EndCommand : Command {
	bool* end;

	EndCommand(bool* end_){
		end = end_;
	}

	void execute() override {
		*end = true;
		std::cout << "End" << std::endl;
	}
};

struct WaitCommand : Command {
	bool* wait;
	std::vector<Timer>* timers;
	int time;

	WaitCommand(std::vector<Timer>* timers_,bool* wait_,int time_){
		wait = wait_;
		timers = timers_;
		time = time_;
	}

	void execute() override {
		std::cout << "started waiting" << std::endl;
		*wait = true;
		Timer timer(time);
		timer.waitingTimer = true;
		timers->push_back(timer);
	}
};

#endif
