/* Corresponding header */
#include "manager_utils/drawing/Text.h"  

/* C system icnludes */

/* C++ system icnludes */
#include <iostream>

/* Third-party icnludes */

/* Own icnludes */
#include "manager_utils/managers/RsrcMgr.h"

Text::~Text() {
    if (_isCreated && !_isDestroyed) {
        destroy();
    }
}

void Text::create(const char* text, int32_t fontId,
    const Color& color, const Point& pos) {
    if (_isCreated) {
        std::cerr << "Error, text with fondId: "
            << fontId << " was already created. Will not create twice." << std::endl;
        return;
    }

    gRsrcMgr->createText(text, color, fontId, _drawParams.textId,
        _drawParams.width, _drawParams.height);
    _drawParams.pos = pos;
    _drawParams.widgetType = WidgetType::TEXT;

    _textContent = text;
    _color = color;
    _fontId = fontId;

    _isCreated = true;
    _isDestroyed = false;
}

void Text::destroy() {
    if (_isDestroyed) {
        std::cerr << "Error, text with textId: " << _drawParams.textId
            << "was already destroyed." << std::endl;
        return;
    }
    _isDestroyed = true;
    _isCreated = false;
    Widget::reset();
}

void Text::setText(const char* text) {
    if (text == _textContent) {
        return;
    }
    gRsrcMgr->reloadText(text, _color, _fontId, _drawParams.textId,
        _drawParams.width, _drawParams.height);
    
}

void Text::setColor(const Color& color) {
    if (_color == color) {
        return;
    }
    _color = color;
    gRsrcMgr->reloadText(_textContent.c_str(), _color, _fontId, _drawParams.textId,
        _drawParams.width, _drawParams.height);
}

std::string Text::getTextContent() const {
    return _textContent;
}
