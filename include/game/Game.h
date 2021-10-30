#ifndef GAME_H
#define GAME_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>

/* Third-party icnludes */

/* Own icnludes */
#include "game/config/GameConfig.h"
#include "manager_utils/drawing/Image.h"
#include "manager_utils/drawing/Text.h"
#include "manager_utils/audio/Sound.h"
//#include "manager_utils/audio/Music.h"
#include "game/entities/Console.h"

/* Forward declaration */
struct InputEvent;

class Game {
public:
    int32_t init(const GameConfig& config);
    void deinit();
    void draw();
    void handleEvent(const InputEvent& e);

private:
    Image gameMapImg;

    Console _console;

    Sound ringSFX;
    //Music ringtoneMusic;
};

#endif