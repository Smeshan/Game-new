#ifndef SOUND_H
#define SOUND_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>

/* Third-party icnludes */

/* Own icnludes */
#include "manager_utils/audio/Audio.h" 

/* Forward Declaration */

class Sound : public Audio {
public:
	~Sound();
	void create(int32_t sndId);
	void destroy();
};
#endif