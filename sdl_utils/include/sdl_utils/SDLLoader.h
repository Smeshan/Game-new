#ifndef SDL_UTILS_SDLLOADER_H_
#define SDL_UTILS_SDLLOADER_H_

/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>

/* Third-party icnludes */

/* Own icnludes */

/* Forward Declaration */

class SDLLoader {
public:
	SDLLoader() = delete;
	~SDLLoader() = default;

	static int32_t init();

	static void deinit();
};

#endif /* SDL_UTILS_SDLLOADER_H_ */
