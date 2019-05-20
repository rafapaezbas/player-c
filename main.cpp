#include "audioUtil.h"
#include "dirReader.h"
#include "StateCollection.h"

int main (int argc, char** argv){

	//PlayingState playingState_{};
	//PausedState pausedState_{};

	//currentState = &playingState_;

	std::string dirPath = "/media/rafa";
	DirReader::readDir(dirPath);
	std::string filePath = "/home/rafa/Escritorio/song2.wav";

	SDL_Init(SDL_INIT_AUDIO);
	loadWavFile(filePath);
	openDevice();
	play();

	bool running = true;
	while(running){
	}

	cleanWav();
	closeDevice();
	SDL_Quit();
	return 0;
}

