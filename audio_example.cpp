#include "audioUtil.h"

std::string filePath = "/home/rafa/Escritorio/song2.wav";


int main (int argc, char** argv){

  SDL_Init(SDL_INIT_AUDIO);
  loadWavFile(filePath);
  openDevice();
  play();

  while(audio.length > 0){
  }

  cleanWav();
  closeDevice();
  SDL_Quit();
  return 0;
}
