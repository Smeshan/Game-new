#ifndef IMAGE_H
#define IMAGE_H
/* C system icnludes */

/* C++ system icnludes */

/* Third-party icnludes */

/* Own icnludes */

/* Forward Declaration */
#include "manager_utils/drawing/Widget.h"

class Image : public Widget {
public:
	~Image();
	void create(int32_t resId, const Point& pos = Point::ZERO);
	void destroy();
};
#endif