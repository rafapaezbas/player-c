#include "audioUtil.h"
#include "dirReader.h"
#include "StateCollection.h"
#include "parser.h"

int main (int argc, char** argv){

  std::vector<std::string> playlist = parser::getPlaylist("/home/rafa/Escritorio/playlist.txt");
  std::string* ptr_playlist = &playlist.at(0); //Pointer to first element of the array

  /**
   * Initialization of state intances, needed for State pointer declared in StateCollection.h, this allow to use
   * State as the abstract class.
   */
  PlayingState playingState_{};
  PausedState pausedState_{};

  ptr_playingState = &playingState_;
  ptr_pausedState = &pausedState_;

  //first state needed
  ptr_currentState = ptr_pausedState;

  //std::string dirPath = "/media/rafa";
  //DirReader::readDir(dirPath);

  SDL_Init(SDL_INIT_AUDIO);
  loadWavFile(*ptr_playlist);
  openDevice();

  play();

  bool running = true;
  while(running){
    if(audio.length == 0){ //If song is finished
      ptr_playlist++;
      pause();
      cleanWav();
      loadWavFile(*ptr_playlist);
      play();
    }
    /**
    int action;
    std::cin >> action;
    if(action == 0){
      ptr_currentState->pauseAction();
    }
    if(action == 1){
      ptr_currentState->playAction();
    }
    **/
  }
  cleanWav();
  closeDevice();
  SDL_Quit();
  return 0;
}

