/* Corresponding header */
#include "manager_utils/drawing/Widget.h"  

/* C system icnludes */

/* C++ system icnludes */
#include <iostream>

/* Third-party icnludes */

/* Own icnludes */
#include "manager_utils/managers/DrawMgr.h"

void Widget::draw() {
    if (_isVisible) {
        gDrawMgr->addDrawCmd(_drawParams);
    }
}

void Widget::reset() {
    _isCreated = false;
    _isDestroyed = true;
    _isVisible = true;
    _isAlphaModulationEnabled = false;

    _drawParams.reset();
}


void Widget::setWidth(int32_t width) {
	_drawParams.width = width;
}

void Widget::setHeight(int32_t height) {
	_drawParams.height = height;
}

void Widget::setOpacity(int32_t opacity) {
    if (!_isAlphaModulationEnabled) {
        std::cerr << "Alpha modulation is not enabled for resId: "
            << _drawParams.resId << ". Opacity is not changed." << std::endl;
        return;
    }
    _drawParams.opacity = opacity;
    gDrawMgr->setWidgetOpacity(_drawParams, opacity);
}

void Widget::setPosition(const Point& pos) {
    _drawParams.pos = pos;
}

void Widget::setPosition(int32_t x, int32_t y) {
    _drawParams.pos.x = x;
    _drawParams.pos.y = y;
}

int32_t Widget::getOpacity() const {
    return _drawParams.opacity;
}

Point Widget::getPosition() const {
    return _drawParams.pos;
}

int32_t Widget::getWidth() const{
	return _drawParams.width;
}

int32_t Widget::getHeight() const{
	return _drawParams.height;
}

void Widget::activateAlphaModulation() {
    if (_isAlphaModulationEnabled) {
        std::cerr << "Alpha modulation is already enabled for resId: " << _drawParams.resId
            << std::endl;
        return;
    }
    _isAlphaModulationEnabled = true;
    gDrawMgr->setWidgetBlendMode(_drawParams, BlendMode::BLEND);
}

void Widget::deactivateAlphaModulation() {
    if (!_isAlphaModulationEnabled) {
        std::cerr << "Alpha modulation was originally not enabled for resId: "
            << _drawParams.resId << std::endl;
        return;
    }
    _isAlphaModulationEnabled = false;
    gDrawMgr->setWidgetBlendMode(_drawParams, BlendMode::NONE);
}

void Widget::show() {
    _isVisible = true;
}

void Widget::hide() {
    _isVisible = false;
}

void Widget::moveRight(int32_t delta) {
    _drawParams.pos.x -= delta;
}

void Widget::moveLeft(int32_t delta) {
    _drawParams.pos.x += delta;
}

void Widget::moveUp(int32_t delta) {
    _drawParams.pos.y -= delta;
}

void Widget::moveDown(int32_t delta) {
    _drawParams.pos.y += delta;
}
