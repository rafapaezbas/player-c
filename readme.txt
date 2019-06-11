What is player-c? 
Player-c is an interpreter for scripted playlists. It uses an embedded Chaiscript interpreter and playback functions based on SDL_mixer library.

What functions can I use? 
-play(file_path,channel) 
-fadeIn(file_path,channel,fadeInTime) 
-fadeOut(channel,fadeOutTime) 
-wait(waitingTime) 
-randomWavFrom(dir_path)

Example:

for(var i = 0; i < 15; ++i) { 
	var song = randomWavFrom("/path/to/music/dir"); 
	fadeIn(song,0,2000);
	wait(4000);
	fadeOut(0,2000);
	wait(3000);
}
