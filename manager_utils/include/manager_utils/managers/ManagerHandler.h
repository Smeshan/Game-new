#ifndef MANAGERHANDLER_H
#define MANAGERHANDLER_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>

/* Third-party icnludes */

/* Own icnludes */
#include "manager_utils/managers/MgrBase.h"

/* Forward Declaration */
struct ManagerHandlerConfig;

class ManagerHandler {
public:
	int32_t init(const ManagerHandlerConfig& config);

	void deinit();

	void process();

private:
	void nullifyGlobalMgr(int32_t mgrIdx);
	MgrBase* _managers[MANAGERS_COUNT];
};

#endif