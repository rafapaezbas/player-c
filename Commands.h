#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include "audioUtil.h"

struct Command {
	virtual void execute(){};
};

struct PlayCommand : Command {
	std::string file;

	PlayCommand(std::string file_){
		file = file_;
	}

	void execute() override{
		//cleanWav();
		//loadWavFile(file);
		//play();
		std::cout << "Played: " + file << std::endl;
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

#endif
