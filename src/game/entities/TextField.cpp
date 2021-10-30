/* Corresponding header */
#include "game/entities/TextField.h"  

/* C system icnludes */

/* C++ system icnludes */
#include <string>

/* Third-party icnludes */

/* Own icnludes */
#include "sdl_utils/InputEvent.h"

int32_t TextField::init(int32_t config) {
    _keySound.create(config);
    addLine();
    return EXIT_SUCCESS;
}

void TextField::deinit() {
    //empty
}

void TextField::draw() {
    if (_textLines.empty()) {
        std::cerr << "Error, passed empty vector of TextLine" << std::endl;
        return;
    }
    for (auto& line : _textLines) {
        line.draw();
    }
}

void TextField::addLine() {
    TextLine newLine;
    newLine.setLineIndx(_currLine);
    _textLines.push_back(newLine);
    _currLine++;
}

void TextField::removeLine() {
    _textLines.pop_back();
    _currLine--;
}

void TextField::handleEvent(const InputEvent& e) {
    if (TouchEvent::UNKNOWN == e.type) {
        return;
    }
    else if (TouchEvent::TYPING == e.type) {
        _textLines[_currLine].addChar(e.text);
        //_keySound.play();
    }
    if (TouchEvent::KEYBOARD_PRESS == e.type) {
        switch (e.key) {
        case Keyboard::KEY_SPACE:
            _textLines[_currLine].procesLastWord();
            break;
        case Keyboard::KEY_BACKSPACE:
        {
            const bool noCharLeft = _textLines[_currLine].removeChar();
            if (noCharLeft && _currLine > 0) {
                removeLine();
            }
        }
        break;
        case Keyboard::KEY_TAB:
            _textLines[_currLine].addTabSpace();
            break;
        case Keyboard::KEY_ENTER:
            addLine();
            break;
        default:
            break;
        }
    }
}
