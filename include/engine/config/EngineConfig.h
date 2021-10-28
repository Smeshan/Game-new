#ifndef ENGINECONFIG_H
#define ENGINECONFIG_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>

/* Third-party icnludes */

/* Own icnludes */
#include "game/config/GameConfig.h"
#include "manager_utils/config/ManagerHandlerConfig.h"

/* Forward Declaration */

struct EngineConfig {
	GameConfig gameConfig;
	ManagerHandlerConfig managerHandlerConfig;
};

#endif