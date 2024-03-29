#ifndef COMMONDEFINES_H
#define COMMONDEFINES_H
/* C system icnludes */

/* C++ system icnludes */
#include <string>
#include <iostream>
#include <dirent.h>

/* Third-party icnludes */

/* Own icnludes */

/* Forward Declaration */

namespace TextureId {

    enum ResourceId {
        ALL_KEYS,
        LAYER_2,
        DOWN,
        GAMEMAP,
        CONSOLE,
        RES_COUNT
    };

} //namespace TextureId

namespace FontId {
    enum FontIdKeys {
        ANGELINE_VINTAGE,
        TERMINAL,
        FONT_COUNT
    };
}

namespace MediaId {
    enum SoundIds {
        RING_SFX,
        SINGLE_KEY_TYPE,
        SOUNDS_COUNT
    };
}

#endif //COMMONDEFINES_H