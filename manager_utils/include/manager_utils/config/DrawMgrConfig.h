#ifndef DRAWMGRCONFIG_H
#define DRAWMGRCONFIG_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>

/* Third-party icnludes */

/* Own icnludes */
#include "sdl_utils/config/MonitorConfig.h"

/* Forward Declaration */

struct DrawMgrConfig {
	MonitorConfig windowConfig;
    int64_t maxFrameRate;

};

#endif // DRAWMGRCONFIG_H