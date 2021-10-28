#ifndef SOUNDCONTAINERCONFIG_H
#define SOUNDCONTAINERCONFIG_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>
#include <unordered_map>

/* Third-party icnludes */

/* Own icnludes */

/* Forward Declaration */

struct SoundConfig {
	std::string length;
	std::string location;
};

struct SoundContainerConfig {
	std::unordered_map<int32_t,SoundConfig> soundConfigs;
};

#endif // SOUNDCONTAINERCONFIG_H