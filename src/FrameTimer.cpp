#include "FrameTimer.h"

FrameTimer::FrameTimer() {
	mStartTicks = 0;
	mPausedTicks = 0;

	mPaused = false;
	mStarted = false;
}

void FrameTimer::start() {
	mStarted = true;
	mPaused = false;

	mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

void FrameTimer::stop() {
	mStarted = false;
	mPaused = true;

	mStartTicks = 0;
	mPausedTicks = 0;
}

void FrameTimer::pause() {
	if (mStarted && !mPaused) {
		mPaused = true;

		mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
	}
}

void FrameTimer::unpause() {
	if (mStarted && mPaused) {
		mPaused = false;

		mStartTicks = SDL_GetTicks() - mPausedTicks;
		mPausedTicks = 0;
	}
}

Uint32 FrameTimer::getTicks() {
	Uint32 time = 0;

	if (mStarted) {
		if (mPaused) {
			time = mPausedTicks;
		} else {
			time = SDL_GetTicks() - mStartTicks;
		}
	}

	return time;
}
