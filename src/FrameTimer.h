#ifndef SRC_FRAMETIMER_H_
#define SRC_FRAMETIMER_H_

#include "SDL2/SDL.h"

class FrameTimer {

public:
	FrameTimer();

	void start();
	void stop();
	void pause();
	void unpause();

	Uint32 getTicks();

	bool isStarted() { return mStarted; }
	bool isPaused() { return mPaused; }

private:
	Uint32 mStartTicks;
	Uint32 mPausedTicks;

	bool mPaused;
	bool mStarted;
};

#endif /* SRC_FRAMETIMER_H_ */
