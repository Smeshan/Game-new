#ifndef THREADUTILS_H
#define THREADUTILS_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>

/* Third-party icnludes */

/* Own icnludes */

/* Forward Declaration */

class Threading {
	public:
    Threading() = delete;

	static void sleepFor(int64_t microseconds);
};

#endif