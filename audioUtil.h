#ifndef AUDIO_UTIL_H
#define AUDIO_UTIL_H

#include <iostream>
#include <SDL2/SDL.h>

void loadWavFile(std::string filePath,bool* deviceIsOpen);
void openDevice();
void cleanWav();
void closeDevice();
void play();
void audioutil_pause();

struct AudioData {
	Uint8* pos;
	Uint32 length;
};

extern AudioData audio;

#endif
