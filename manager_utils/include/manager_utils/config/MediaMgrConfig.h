#ifndef MEDIAMGRCONFIG_H
#define MEDIAMGRCONFIG_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>

/* Third-party icnludes */

/* Own icnludes */
#include "sdl_utils/config/SoundContainerConfig.h"
//#include "sdl_utils/config/MusicContainerConfig.h"

/* Forward Declaration */

struct MediaMgrConfig {
public:
    SoundContainerConfig soundContainerConfig;
    //MusicContainerConfig musicContainerConfig;
};


#endif // MEDIAMGRCONFIG_H