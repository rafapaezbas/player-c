#include "audioUtil.h"
#include "dirReader.h"
#include "parser.h"
#include "timer.h"
#include "State.h"
#include "Commands.h"
#include "chaiscript/chaiscript.hpp"

State state;

/**
 * The definition of this functions will be "embdedded" in the chai interpreter;
 */
void play_func(const std::string &t_name,int channel) {
	PlayCommand* playCommand = new PlayCommand(t_name,&state.deviceIsOpen,channel);
	state.commands.push_back(playCommand);	
}

void wait_func(const int &t_time) {
	WaitCommand* waitCommand = new WaitCommand(&state.timers,&state.wait,t_time);
	state.commands.push_back(waitCommand);	
}

std::string random_wav_from_func(const std::string &t_path) {
	std::vector<std::string> paths = dir::readDir(t_path);
	//Keep looping until wav file found
	while(true){
		std::string path = paths.at(rand() % paths.size());
		std::size_t found = path.find(".wav");
		if (found != std::string::npos){
			return path;
		}
	}
}

int main (int argc, char** argv){
	
	
	//add functions to chai engine
	chaiscript::ChaiScript chai;
	chai.add(chaiscript::fun(&play_func), "play");
	chai.add(chaiscript::fun(&wait_func), "wait");
	chai.add(chaiscript::fun(&random_wav_from_func), "randomWavFrom");

	//interpret chai script
	std::string script = parser::getScript("/home/rafa/Escritorio/sdl_tutorial/example.chai");
	chai(script);
	
	//Always add the end command as the last command
	EndCommand endCommand = EndCommand(&state.end);
	state.commands.push_back(&endCommand);	

	SDL_Init(SDL_INIT_AUDIO);

	bool running = true;
	int iterator = 0;
	while(running){
		while(!state.wait && !state.end){
			state.commands.at(iterator)->execute();
			iterator++;
			state.runTimers();
		}
		state.runTimers();
	}

	cleanChunks();
	Mix_CloseAudio();
	SDL_Quit();
	return 0;
}


