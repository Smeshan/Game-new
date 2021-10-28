/* Corresponding header */
#include "manager_utils/managers/MediaMgr.h"  

/* C system icnludes */

/* C++ system icnludes */
#include <iostream>

/* Third-party icnludes */

/* Own icnludes */
#include "manager_utils/config/MediaMgrConfig.h"

MediaMgr* gMediaMgr = nullptr;

int32_t MediaMgr::init(const MediaMgrConfig& config) {
    if (EXIT_SUCCESS != SoundContainer::init(config.soundContainerConfig)) {
        std::cerr << "SoundContainer::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    /* if (EXIT_SUCCESS != MusicContainer::init(config.musicContainerConfig)) {
        std::cerr << "MusicContainer::init() failed." << std::endl;
        return EXIT_FAILURE;
    } */

    return EXIT_SUCCESS;
}

void MediaMgr::deinit() {
    SoundContainer::deinit();
    //MusicContainer::deinit();
}

void MediaMgr::process() {

}