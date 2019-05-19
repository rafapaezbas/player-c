#include "audioUtil.h" 

AudioData audio;

SDL_AudioSpec wavSpec;
Uint8* wavStart;
Uint32 wavLength;

SDL_AudioDeviceID device;

/**
   This funtion is called as callback after SDL_PauseAudioDevice(device,0);
 */
void myAudioCallback(void* userdata, Uint8* stream, int streamLength){
  AudioData* audio = (AudioData*) userdata;
  if(audio->length == 0){
    return;
  }
  Uint32 length = (Uint32) streamLength;
  length = (length > audio->length ? audio->length: length);

  //Copy to buffer from audio pos, given length
  SDL_memcpy(stream,audio->pos,length);
  audio->pos += length;
  audio->length -= length; 

}

/**
   Loads a wav file given a path, fills sdl audio specs, a direction of pointer of an unsigned int8 (memory where file begins)
   and a direction of a unsigned int32 that is the file length,asign then the values to the struct created 
*/
void loadWavFile(std::string filePath){
  if(SDL_LoadWAV(&filePath[0], &wavSpec, &wavStart, &wavLength) == NULL){
    std::cerr << "Error " << filePath << " could not be lodaded as an audio file" << std::endl;
    return;
  }
  audio.pos = wavStart;
  audio.length = wavLength;
  wavSpec.callback = myAudioCallback;
  wavSpec.userdata = &audio;
  std::cout << "Loaded: " << filePath << std::endl;
}

/**
   Open default soudn device, pass wavSpec to check compatibility
 */
void openDevice(){
  device = SDL_OpenAudioDevice(NULL,0,&wavSpec,NULL,SDL_AUDIO_ALLOW_ANY_CHANGE);
  if(device == 0){
    std::cerr << SDL_GetError() << std::endl;
    return;
  }
}

void play(){
  SDL_PauseAudioDevice(device,0);
}

void pause(){
  SDL_PauseAudioDevice(device,0);
}

void cleanWav(){
  SDL_FreeWAV(wavStart);
}

void closeDevice(){
  SDL_CloseAudioDevice(device);
}

