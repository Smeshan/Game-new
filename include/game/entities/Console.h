#ifndef CONSOLE_H
#define CONSOLE_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>
#include <string>

/* Third-party icnludes */

/* Own icnludes */

#include "game/entities/TextField.h"  

/* Forward Declaration */
struct InputEvent;
struct GameConfig;

class Console
{
public:
	int32_t init(const GameConfig& config);
	void deinit();
	void draw();
	void handleEvent(const InputEvent& e);

private:
	Image _consoleImg;
	TextField _textField;
};
#endif