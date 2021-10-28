/* Corresponding header */
#include "manager_utils/drawing/Image.h"  

/* C system icnludes */

/* C++ system icnludes */
#include <iostream>

/* Third-party icnludes */

/* Own icnludes */
#include "manager_utils/managers/RsrcMgr.h"

Image::~Image() {
    if (_isCreated && !_isDestroyed) {
        destroy();
    }
}

void Image::create(int32_t resId, const Point& pos) {
    if (_isCreated) {
        std::cerr << "Error, image with resId: "
            << resId << " was already created. Will not create twice." << std::endl;
        return;
    }
    Rectangle rect = gRsrcMgr->getImageFrame(resId);
    _drawParams.resId = resId;
    _drawParams.width = rect.w;
    _drawParams.height = rect.h;
    _drawParams.pos = pos;
    _drawParams.widgetType = WidgetType::IMAGE;

    _isCreated = true;
    _isDestroyed = false;
}

void Image::destroy() {
    if (_isDestroyed) {
        std::cerr << "Error, image with resID: " << _drawParams.resId 
        << "was already destroyed." << std::endl;
        return;
    }
    _isDestroyed = true;
    _isCreated = false;
    Widget::reset();
}
