#ifndef TEXTCONTAINERCONFIG_H
#define TEXTCONTAINERCONFIG_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>
#include <unordered_map>

/* Third-party icnludes */

/* Own icnludes */

/* Forward Declaration */

struct FontConfig {
	std::string location;
	int32_t fontSize = 0;
};

struct TextContainerConfig {
	std::unordered_map<int32_t, FontConfig> fontConfigs;
};

#endif // TEXTCONTAINERCONFIG_H