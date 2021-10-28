#ifndef TEXT_H
#define TEXT_H
/* C system icnludes */

/* C++ system icnludes */
#include <string>

/* Third-party icnludes */

/* Own icnludes */

/* Forward Declaration */
#include "manager_utils/drawing/Widget.h"
#include "utils/drawing/Color.h"

class Text : public Widget {
public:
	~Text();
	void create(const char* text, int32_t fontId,
		const Color& color, const Point& pos = Point::ZERO);
	void destroy();
	void setText(const char* text);
	void setColor(const Color& color);

	std::string getTextContent() const;

private:
	std::string _textContent;
	Color _color = Colors::BLACK;
	int32_t _fontId = INVALID_RESOURCES_ID;

};
#endif