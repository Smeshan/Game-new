/* Corresponding header */
#include "game/Game.h"

/* C system includes */

/* C++ system icnludes */
#include <iostream>

/* Third-party icnludes */

/* Own icnludes */
#include "sdl_utils/InputEvent.h"

int32_t Game::init(const GameConfig& config) {

    gameMapImg.create(config.gameMapId);
    ringSFX.create(config.ringSFXId);
    
    _console.init(config);

    //ringtoneMusic.create();
    //SDL_StartTextInput();

    return EXIT_SUCCESS;
}

void Game::draw() {
    _console.draw();
}

void Game::handleEvent(const InputEvent& e) {
    _console.handleEvent(e);
}

void Game::deinit() {
    //destructors will do the work
}