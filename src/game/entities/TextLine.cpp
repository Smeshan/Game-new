/* Corresponding header */
#include "game/entities/TextLine.h"  

/* C system icnludes */

/* C++ system icnludes */

/* Third-party icnludes */

/* Own icnludes */
#include "game/entities/KeyWords.h"

constexpr auto TAB_SPACES_COUNT = 3;

void TextLine::setLineIndx(const int32_t indx) {
    _indx = indx;
}

void TextLine::draw() {
    for (auto& letter : _line) {
        //QUESTION Why can't draw const widget?
        letter.draw();
    }
}

void TextLine::procesLastWord() {
    size_t lastWordBegin = 0;
    const std::string lastWord = getLastWord(lastWordBegin);
    if (KeyWords::checkForKeyWord(lastWord)) {
        for (size_t i = _currChar; i > lastWordBegin; --i) {
            // QUESTION How to prevent i to not go into -1 state
            _line[i - 1].setColor(Colors::CYAN);
        }
    }
}

void TextLine::addChar(const char* input) {
    _text += input;
    Text newChar;
    newChar.create(input, _textFontId, Colors::WHITE, Point(100 + 10 * _currChar, 100 + 20 * _indx));
    _line.push_back(newChar);
    _currChar++;
    //TODO add keyword check after ENTER
}

bool TextLine::removeChar() {
    if (_text.length() > 0) {
        _text.pop_back();
        _line.pop_back();
        _currChar--;
        return false;
    }
    return true;
}

void TextLine::addTabSpace() {
    for (int i = 0; i < TAB_SPACES_COUNT; ++i) {
        _text += " ";
        Text newWhiteSpace;
        newWhiteSpace.create(" ", _textFontId, Colors::WHITE, Point(100 + 10 * _currChar, 100 + 20 * _indx));
        _currChar++;
        _line.push_back(newWhiteSpace);
    }
}

std::string TextLine::getLastWord(size_t& begin) const{
    const size_t end = _text.length() - 1;
    begin = _text.rfind(' ', end) + 1;
    if (begin == std::string::npos) {
        begin = 0;
    }
    return _text.substr(begin, end - begin + 1);
}