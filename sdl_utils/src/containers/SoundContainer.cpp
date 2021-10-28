/* Corresponding header */
#include "sdl_utils/containers/SoundContainer.h"  

/* C system icnludes */

/* C++ system icnludes */
#include <iostream>

/* Third-party icnludes */

/* Own icnludes */
#include "sdl_utils/Media.h"

int32_t SoundContainer::init(const SoundContainerConfig& configs) {
    for (const auto& pair : configs.soundConfigs) {
        const auto key = pair.first;
        const auto& soundConfig = pair.second;

        if (EXIT_SUCCESS != loadSingleSoundRes(soundConfig, key)) {
            std::cerr << "loadSingleSoundRes() failed for file: "
                << soundConfig.location << std::endl;
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

void SoundContainer::deinit() {
    for (auto& pair : _sounds) {
        Media::freeSound(pair.second);
    }
}

int32_t SoundContainer::loadSingleSoundRes(const SoundConfig& sndConfig,
                                           const int32_t sndId) {
    Mix_Chunk* sound = nullptr;
    if (EXIT_SUCCESS != Media::createSoundFromFile(sndConfig.location.c_str(), sound)) {
        std::cerr << "Media::createSoundFromFile() failed for file: "
        << sndConfig.location << std::endl;
        return EXIT_FAILURE;
    }
    _sounds[sndId] = sound;

    return EXIT_SUCCESS;                                         
}
