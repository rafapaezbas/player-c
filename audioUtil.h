#ifndef AUDIO_UTIL_H
#define AUDIO_UTIL_H

#include <iostream>
#include <SDL2/SDL.h>
#include "SDL2/SDL_mixer.h"

void loadWavFile(std::string filePath,int channel,bool* deviceIsOpen);
void openDevice();
void cleanChunk(int channel);
void cleanChunks();
void play(int channel);
void audioutil_pause(int channel);

#endif
