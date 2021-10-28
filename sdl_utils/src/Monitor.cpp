/* Corresponding header */
#include "sdl_utils/Monitor.h"

/* C system icnludes */

/* C++ system icnludes */
#include <iostream>

/* Third-party icnludes */
#include <SDL.h>
#include <SDL_video.h>
#include <sdl_utils/config/MonitorConfig.h>

/* Own icnludes */

int32_t Monitor::init(const MonitorConfig confg) {
    Point finalPos;
    if (confg.windowPos == Point::UNDEFINED) {
        finalPos.x = SDL_WINDOWPOS_UNDEFINED;
        finalPos.y = SDL_WINDOWPOS_UNDEFINED;
    }
    else {
        finalPos = confg.windowPos;
    }
    _window = SDL_CreateWindow(confg.windowName.c_str(), finalPos.x, finalPos.y,
        confg.windowHeight, confg.windowWidth, confg.windowFlags);
    if (_window == nullptr) {
        std::cerr << "SDL_CreateWindow() failed. Reason: " << SDL_GetError() << std::endl;
    }
    return EXIT_SUCCESS;
}

Monitor::~Monitor() {
    deinit();
}

void Monitor::deinit() {

    if (_window != nullptr) {
        SDL_DestroyWindow(_window);
        _window = nullptr;
    }
}

void Monitor::updateWindowSurface() {
    if (EXIT_SUCCESS != SDL_UpdateWindowSurface(_window)) {
        std::cerr << "SDL_UpdateWindowSurface() failed. Reason: " << SDL_GetError()
            << std::endl;
    }
}

SDL_Window* Monitor::getWindow() {
    return _window;
}