#include <iostream>
#include "audioUtil.h"

struct State{
	virtual void playAction(){};
	virtual void pauseAction(){};
};

/**
 * Pointers will point to instances intialized in the main method
 */
extern State* ptr_currentState = NULL;
extern State* ptr_playingState = NULL;
extern State* ptr_pausedState = NULL;

struct PlayingState : State {
	void playAction() override {
		ptr_currentState = ptr_playingState;
	}
	void pauseAction() override {
		pause();
		std::cout << "Paused music" << std::endl;
		ptr_currentState = ptr_pausedState;
	}
};

struct PausedState : State {
	void playAction() override {
		play();
		std::cout << "Resumed music" << std::endl;
		ptr_currentState = ptr_playingState;
	}
	void pauseAction() override {
		ptr_currentState = ptr_pausedState;
	}
};

