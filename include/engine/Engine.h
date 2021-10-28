#ifndef ENGINE_H
#define ENGINE_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>

/* Third-party icnludes */

/* Own icnludes */
#include "game/Game.h"
#include "sdl_utils/InputEvent.h"
#include "manager_utils/managers/ManagerHandler.h"

/* Forward Declaration */
struct EngineConfig;

class Engine {
public:
    int32_t init(const EngineConfig& config);
    void deinit();
    void start();

private:
    void mainLoop();
    void drawFrame();
    bool processFrame();
    void handleEvent();

    void limitFPS(int64_t limitTimeMicroSeconds);

    ManagerHandler _managerHandler;
    InputEvent _event;
    Game _game;
    
};
#endif