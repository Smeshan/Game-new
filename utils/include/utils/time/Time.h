#ifndef TIMER_H
#define TIMER_H
/* C system icnludes */

/* C++ system icnludes */

/* Third-party icnludes */
#include <chrono>
#include <cstdlib>

/* Own icnludes */

/* Forward Declaration */

class Time {

public:
    /** @brief used to measure elapsed time since last invoke of this method
    *   NOTE: .getElapsed() method simply measures time between 2
    *   points of time.
    * */

    Time& getElapsed();
    int64_t toSeconds() const;
    int64_t toMilliseconds() const;
    int64_t toMicroseconds() const;
    int64_t toNanoseconds() const;

private:
    std::chrono::time_point<std::chrono::steady_clock> _now =
        std::chrono::steady_clock::now();
    std::chrono::time_point<std::chrono::steady_clock> _elapsedLastCall;
};
#endif