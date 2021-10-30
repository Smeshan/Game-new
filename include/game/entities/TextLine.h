#ifndef TEXTLINE_H
#define TEXTLINE_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>
#include <vector>

/* Third-party icnludes */

/* Own icnludes */
#include "manager_utils/drawing/Text.h"
#include "common/CommonDefines.h"

/* Forward Declaration */

class TextLine
{
public:
	void setLineIndx(const int32_t indx);
	void draw();
	void procesLastWord();
	void addChar(const char* input);
	bool removeChar();
	void addTabSpace();

	std::string getLastWord(size_t& begin) const;

private:
	int32_t _indx;
	int32_t _textFontId = FontId::TERMINAL;
	int32_t _currChar = 0;
	std::vector<Text> _line;
	std::string _text;

};
#endif