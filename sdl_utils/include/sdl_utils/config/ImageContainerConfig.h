#ifndef IMAGECONTAINERCONFIG_H
#define IMAGECONTAINERCONFIG_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>
#include <vector>
#include <string>

/* Third-party icnludes */

/* Own icnludes */

/* Forward Declaration */

struct ImageConfig {
	std::string name;
	std::string location;
	int32_t width = 0;
	int32_t height = 0;
	int32_t id = 0;
};

struct ImageContainerConfig {
	std::vector<ImageConfig> imageData;
};
#endif