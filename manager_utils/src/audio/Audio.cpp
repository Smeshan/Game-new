/* Corresponding header */
#include "manager_utils/audio/Audio.h"  

/* C system icnludes */

/* C++ system icnludes */
#include <iostream>

/* Third-party icnludes */

/* Own icnludes */
#include "manager_utils/managers/MediaMgr.h"

void Audio::play() {
    if (_isPlaying) {
        std::cerr << "Audio file is currently playing." << std::endl;
    }
    gMediaMgr->addPlaySoundCmd(_sndId);
    _isPlaying = true;
}

void Audio::stop() {
    if (!_isPlaying) {
        std::cerr << "Audio file is already stoped." << std::endl;
    }
    _isPlaying = false;
}

void Audio::reset() {
    _isCreated = false;
	_isDestroyed = true;
	_isPlaying = false;
}
