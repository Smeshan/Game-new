#ifndef SOUNDCONTAINER_H
#define SOUNDCONTAINER_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>
#include <unordered_map>

/* Third-party icnludes */

/* Own icnludes */
#include "sdl_utils/config/SoundContainerConfig.h"

/* Forward Declaration */
struct Mix_Chunk;

class SoundContainer {
public:
	
protected:

	int32_t playSoundCmd(const int32_t sndId);
	int32_t init(const SoundContainerConfig& configs);
	void deinit();

private:

	int32_t loadSingleSoundRes(const SoundConfig& sndConfig, const int32_t sndId);

	std::unordered_map<int32_t, Mix_Chunk*> _sounds;
};
#endif