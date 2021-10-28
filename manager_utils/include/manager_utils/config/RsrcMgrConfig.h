#ifndef RSRCMGRCONFIG_H
#define RSRCMGRCONFIG_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>

/* Third-party icnludes */

/* Own icnludes */
#include "sdl_utils/config/ImageContainerConfig.h"
#include "sdl_utils/config/TextContainerConfig.h"

/* Forward Declaration */

struct RsrcMgrConfig {
    ImageContainerConfig imageContainerConfig;
    TextContainerConfig textContainerConfig;
};

#endif // RSRCMGRCONFIG_H