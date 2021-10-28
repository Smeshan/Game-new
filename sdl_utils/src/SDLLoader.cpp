/* Corresponding header */
#include "sdl_utils/SDLLoader.h"

/* C system icnludes */

/* C++ system icnludes */
#include <cstdlib>
#include <iostream>

/* Third-party icnludes */
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

/* Own icnludes */

int32_t SDLLoader::init() {
	if (EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO)) {
		std::cerr << "SDL_Init(SDL_INIT_VIDEO) failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != TTF_Init()) {
		std::cerr << "TTF_Init() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	const int32_t imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		std::cerr << "SDL_image could not be initialised! SDL_image Error: " << IMG_GetError()
				<< std::endl;

		return EXIT_FAILURE;
	}

	if (0 > Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)) {
		std::cerr << "SDL_mixer could not be initialised! SDL_mixer Error: " << Mix_GetError()
				<< std::endl;

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void SDLLoader::deinit() {
	Mix_Quit();
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}
