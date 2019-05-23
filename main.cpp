#include "audioUtil.h"
#include "dirReader.h"
#include "parser.h"
#include "timer.h"
#include "State.h"
#include "Commands.h"

int main (int argc, char** argv){
	State state;

	PlayCommand playCommand = PlayCommand("/home/rafa/Escritorio/song.wav");
	EndCommand endCommand = EndCommand(&state.end);
	state.commands.push_back(&playCommand);	
	state.commands.push_back(&endCommand);	

	SDL_Init(SDL_INIT_AUDIO);
	openDevice();

	bool running = true;
	int iterator = 0;
	while(running){
		while(!state.wait && !state.end){
			state.commands.at(iterator)->execute();
			iterator++;
		}
	}

	cleanWav();
	closeDevice();
	SDL_Quit();
	return 0;
}

