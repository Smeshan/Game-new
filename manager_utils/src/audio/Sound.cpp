/* Corresponding header */
#include "manager_utils/audio/Sound.h"  

/* C system icnludes */

/* C++ system icnludes */
#include <iostream>

/* Third-party icnludes */

/* Own icnludes */
#include "manager_utils/managers/MediaMgr.h"

Sound::~Sound() {
    if (_isCreated && !_isDestroyed) {
        destroy();
    }
}
void Sound::create(int32_t sndId) {
    if (_isCreated) {
        std::cerr << "Error, sound with sndId: "
            << sndId << " was already created. Will not create twice." << std::endl;
        return;
    }
    _sndId = sndId;
    _isCreated = true;
    _isDestroyed = false;
}

void Sound::destroy() {
    if (_isDestroyed) {
        std::cerr << "Error, sound was already destroyed." << std::endl;
        return;
    }
    _isDestroyed = true;
    _isCreated = false;
    Audio::reset();
}