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
    helloText.create("Elevator manager", config.textFondId, Colors::BLACK);
    ringSFX.create(config.ringSFXId);
    //ringtoneMusic.create();

    //"../resources/sounds/sound.wav"

    return EXIT_SUCCESS;
}

void Game::draw() {
    gameMapImg.draw();
    helloText.draw();
}

void Game::handleEvent(const InputEvent& e) {
    if (TouchEvent::KEYBOARD_PRESS != e.type) {
        return;
    }

    switch (e.key) {
    case Keyboard::KEY_UP:
        gameMapImg.moveUp(10);
        break;
    case Keyboard::KEY_DOWN:
        gameMapImg.moveDown(10);
        break;
    case Keyboard::KEY_LEFT:
        gameMapImg.moveLeft(10);
        break;
    case Keyboard::KEY_RIGHT:
        gameMapImg.moveRight(10);
        break;
    case Keyboard::KEY_B:
        gameMapImg.setHeight(gameMapImg.getHeight() * 2);
        gameMapImg.setWidth(gameMapImg.getWidth() * 2);
        break;
    case Keyboard::KEY_1:
        ringSFX.play();
        break;
    case Keyboard::KEY_2:
        //ringtoneMusic.play();
        break;
    default:
        break;
    }
}

void Game::deinit() {
    //destructors will do the work
}