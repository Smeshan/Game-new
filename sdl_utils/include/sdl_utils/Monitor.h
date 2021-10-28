/* C system icnludes */

/* C++ system icnludes */
#include <cstdlib>

/* Third-party icnludes */

/* Own icnludes */

/* Forward Declaration */
struct SDL_Window;
struct MonitorConfig;

#ifndef SDL_UTILS_MONITOR_H_
#define SDL_UTILS_MONITOR_H_

class Monitor {
public:
	Monitor() = default;
	~Monitor();

	Monitor(const Monitor &other) = delete;
	Monitor(Monitor &&other) = delete;

	Monitor& operator=(const Monitor &other) = delete;
	Monitor& operator=(Monitor &&other) = delete;

	int32_t init(const MonitorConfig confg);

	void deinit();
	
	void updateWindowSurface();

	SDL_Window* getWindow();

private:
	SDL_Window* _window = nullptr;
	
};

#endif /* SDL_UTILS_MONITOR_H_ */
