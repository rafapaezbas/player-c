#include <iostream>
#include <SDL2/SDL.h>

void loadWavFile(std::string filePath);
void openDevice();
void cleanWav();
void closeDevice();
void play();
void pause();

struct AudioData {
  Uint8* pos;
  Uint32 length;
};

extern AudioData audio;
