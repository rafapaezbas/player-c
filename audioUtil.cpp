#include "audioUtil.h" 

Mix_Chunk* channels[2];

void loadWavFile(std::string filePath,int channel, bool* deviceIsOpen){
	if(!*deviceIsOpen){
		openDevice();
		*deviceIsOpen = true;
	}
	channels[channel] = Mix_LoadWAV(filePath.c_str()); //Convert it to *cons char*
	if (channels[channel] == NULL){
		std::cout << "Could not load the file: " + filePath << std::endl;
	}
}

void openDevice(){
	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ){
		return;    
	}
}

void play(int channel){
	Mix_PlayChannel(channel, channels[channel], 0);
}

void fadeIn(int channel, int time){
	Mix_FadeInChannel(channel, channels[channel], 0, time);
}

void audioutil_pause(int channel){
	if(Mix_Playing(channel)){
		Mix_Pause(channel);
	}
}

void cleanChunk(int channel){
	Mix_FreeChunk(channels[channel]);
}

void cleanChunks(){
	Mix_FreeChunk(channels[0]);
	Mix_FreeChunk(channels[1]);
}


