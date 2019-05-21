#include "audioUtil.h"
#include "dirReader.h"
#include "StateCollection.h"

int main (int argc, char** argv){

	PlayingState playingState_{};
	PausedState pausedState_{};

	ptr_playingState = &playingState_;
	ptr_pausedState = &pausedState_;

	ptr_currentState = ptr_pausedState;

	std::string dirPath = "/media/rafa";
	//DirReader::readDir(dirPath);
	std::string filePath = "/home/rafa/Escritorio/song2.wav";

	SDL_Init(SDL_INIT_AUDIO);
	loadWavFile(filePath);
	openDevice();

	ptr_currentState->playAction();

	bool running = true;
	while(running){
		int action;
		std::cin >> action;
		if(action == 0){
			ptr_currentState->pauseAction();
		}
		if(action == 1){
			ptr_currentState->playAction();
		}
	}

	cleanWav();
	closeDevice();
	SDL_Quit();
	return 0;
}

