#ifndef AUDIO_H
#define AUDIO_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>

/* Third-party icnludes */

/* Own icnludes */

/* Forward Declaration */

class Audio {
public:
	void play();
	void stop();
	void reset();

protected:
	bool _isCreated = false;
	bool _isDestroyed = true;
	bool _isPlaying = false;

	int32_t _sndId;
};

#endif