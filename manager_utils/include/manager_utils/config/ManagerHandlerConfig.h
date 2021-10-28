#ifndef MANAGERHANDLERCONFIG_H
#define MANAGERHANDLERCONFIG_H
/* C system icnludes */

/* C++ system icnludes */

/* Third-party icnludes */

/* Own icnludes */
#include "manager_utils/config/DrawMgrConfig.h"
#include "manager_utils/config/RsrcMgrConfig.h"
#include "manager_utils/config/MediaMgrConfig.h"

/* Forward Declaration */

struct ManagerHandlerConfig {
    DrawMgrConfig drawMgrConfig;
    RsrcMgrConfig rsrcMgrConfig;
    MediaMgrConfig mediaMgrConfig;
};

#endif // MANAGERHANDLERCONFIG_H