#ifndef WIDGET_H
#define WIDGET_H
/* C system icnludes */

/* C++ system icnludes */

/* Third-party icnludes */

/* Own icnludes */

/* Forward Declaration */
#include "utils/drawing/DrawParams.h"

class Widget {
public:
	void draw();
	void reset();

	void setWidth(int32_t width);
	void setHeight(int32_t height);

	void setOpacity(int32_t opacity);
	void setPosition(const Point& pos);
	void setPosition(int32_t x, int32_t y);

	int32_t getOpacity() const;
	Point getPosition() const;

	int32_t getWidth() const;
	int32_t getHeight() const;

	void activateAlphaModulation();
	void deactivateAlphaModulation();
	void show();
	void hide();

	void moveRight(int32_t delta);
	void moveLeft(int32_t delta);
	void moveUp(int32_t delta);
	void moveDown(int32_t delta);
protected:
	DrawParams _drawParams;
	bool _isCreated = false;
	bool _isDestroyed = true;
	bool _isVisible = true;
	bool _isAlphaModulationEnabled = false;
};

#endif