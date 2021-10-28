/* Corresponding header */
#include "utils/thread/ThreadUtils.h"

/* C system icnludes */

/* C++ system icnludes */

/* Third-party icnludes */

/* Own icnludes */

#ifdef _WIN32
#include <windows.h>
#else
#include <thread>
#endif
void Threading::sleepFor(int64_t microseconds) {
#ifdef _WIN32
    const DWORD milliseconds = static_cast & lt;
    DWORD &gt;
    (microseconds / 1000);
    Sleep(milliseconds); //sleep uses milliseconds
#else
    std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
#endif
}