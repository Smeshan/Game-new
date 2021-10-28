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

int32_t SoundContainer::playSoundCmd(const int32_t sndId) {
    const auto it = _sounds.find(sndId);
    if (it == _sounds.end()) {
         std::cerr << "Can't play sound. Sound with sndID: " << sndId
         << " not in the SoundConntainer" << std::endl;
         return EXIT_FAILURE;
    }
    if (EXIT_SUCCESS != Mix_PlayChannel( -1, it->second, 0 )) { // channel, chunk, loop
        std::cerr << "Mix_PlayChannel() failed. Error: "
        << Mix_GetError() << std::endl;
        return EXIT_FAILURE;
    } 
    return EXIT_SUCCESS;
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
