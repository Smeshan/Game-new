#ifndef MONITORCONFIG_H
#define MONITORCONFIG_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdlib>
#include <string>
#include <array>
#include <unordered_map>

/* Third-party icnludes */

/* Own icnludes */
#include <utils/drawing/Point.h>

/* Forward Declaration */

enum displayConfig {
    WINDOW_NAME,
    DISPLAY_HEIGHT,
    DISPLAY_WIDTH,
    DISPLAY_CONFIG_COUNT
};

const std::array<std::string, DISPLAY_CONFIG_COUNT> displayConfigStr{
    "WINDOW_NAME",
    "DISPLAY_HEIGHT",
    "DISPLAY_WIDTH"};

typedef std::unordered_map<std::string, std::string> configData;

enum WindowFlags {
	WINDOW_SHOWN = 4,
	WINDOW_FULLSCREEN = 4097
};

struct MonitorConfig {
	std::string windowName = "";
	Point windowPos = Point::UNDEFINED;

	int32_t windowWidth = 0;
	int32_t windowHeight = 0;
	WindowFlags windowFlags = WINDOW_SHOWN;
};

#endif