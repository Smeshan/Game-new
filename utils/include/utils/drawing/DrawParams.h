#ifndef DRAWPARAMS_H
#define DRAWPARAMS_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>

/* Third-party icnludes */

/* Own icnludes */
#include "utils/drawing/Point.h"

/* Forward Declaration */

inline constexpr int32_t FULL_OPACITY = 255;
inline constexpr int32_t ZERO_OPACITY = 0;

inline constexpr auto INVALID_RESOURCES_ID = -1;

enum class BlendMode : uint8_t {
    NONE = 0, //value for SDL_BLENDMODE_NONE
    BLEND = 1, //value for SDL_BLENDMODE_BLEND
    ADD = 2, //value for SDL_BLENDMODE_ADD
    MOD = 4 //value for SDL_BLENDMODE_MODE
};

enum class WidgetType : uint8_t {
    IMAGE,
    TEXT,
    UNKNOWN
};

class DrawParams {
public:
    void reset();
    // Top left position of texture
    Point pos = Point::UNDEFINED;

    //Draw dimensions of the texture
    int32_t width = 0;
    int32_t height = 0;

    int32_t opacity = FULL_OPACITY;
    //unique resourceId
    union {
        int32_t resId = INVALID_RESOURCES_ID;
        int32_t textId;
    };

    WidgetType widgetType = WidgetType::UNKNOWN;
};
#endif