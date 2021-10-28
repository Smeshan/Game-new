/* Corresponding header */
#include "engine/Engine.h"

/* C system icnludes */

/* C++ system icnludes */
#include <iostream>

/* Third-party icnludes */

/* Own icnludes */
#include "engine/config/EngineConfig.h"
#include "utils/thread/ThreadUtils.h"
#include "utils/time/Time.h"
#include "manager_utils/managers/DrawMgr.h"

const constexpr auto MICROSEC_IN_SECOND = 100000;

int32_t Engine::init(const EngineConfig& config) {

    if (EXIT_SUCCESS != _managerHandler.init(config.managerHandlerConfig)) {
        std::cerr << "_managerHandler.init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    if (EXIT_SUCCESS != _event.init()) {
        std::cerr << "_event.init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    if (EXIT_SUCCESS != _game.init(config.gameConfig)) {
        std::cerr << "_game.init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void Engine::deinit() {
    _game.deinit();
    _event.deinit();
    _managerHandler.deinit();
}

void Engine::start() {
    mainLoop();
}

void Engine::mainLoop() {
    Time time;

    while (true) {
        time.getElapsed();
        const bool shouldExit = processFrame();
        if (shouldExit) {
            break;
        }

        limitFPS(time.getElapsed().toMicroseconds());
    }
}

void Engine::drawFrame() {
    gDrawMgr->clearScreen();

    _game.draw();

    gDrawMgr->finishFrame();
}

bool Engine::processFrame() {
    while (_event.pollEvent()) {
        if (_event.checkForExitRequest()) {
            return true;
        }
        handleEvent();
    }
    drawFrame();

    return false;
}

void Engine::handleEvent() {
    _game.handleEvent(_event);
}

/* working in microseconds */
void Engine::limitFPS(const int64_t elapsedTime) {
    constexpr auto maxFrames = 30;
    constexpr auto micSecondsPerFrame = MICROSEC_IN_SECOND / maxFrames;
    const int64_t sleepDuration = micSecondsPerFrame - elapsedTime;
    if (sleepDuration > 0) {
        Threading::sleepFor(sleepDuration);
    }
}