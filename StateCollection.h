#include <iostream>

struct State{
	virtual void play(){};
	virtual void pause(){};
};

extern State* currentState;
extern State* playingState;
extern State* pausedState;

struct PlayingState : State {
	void play() override {
		currentState = playingState;
	}
	void pause() override {
		currentState = pausedState;
	}
};

struct PausedState : State {
	void play() override {
		currentState = playingState;
	}
	void pause() override {
		currentState = pausedState;
	}
};

