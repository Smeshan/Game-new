#ifndef UTILS_DRAWING_POINT_H_
#define UTILS_DRAWING_POINT_H_

/* C system icnludes */

/* C++ system icnludes */
#include <cstdlib>

/* Third-party icnludes */

/* Own icnludes */

/* Forward Declaration */


struct Point {
	Point() = default;
	Point(int32_t inputX, int32_t inputY);

	int32_t x = 0;
	int32_t y = 0;
	
	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;

	static const Point ZERO;
	static const Point UNDEFINED;
};

#endif /* UTILS_DRAWING_POINT_H_ */
