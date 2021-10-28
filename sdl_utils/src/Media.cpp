/* Corresponding header */
#include "sdl_utils/Media.h"  

/* C system icnludes */

/* C++ system icnludes */
#include <iostream>
#include <cstdint>

/* Third-party icnludes */

/* Own icnludes */

int32_t Media::createSoundFromFile(const char* filePath, Mix_Chunk*& outSound) {
    outSound = Mix_LoadWAV(filePath);
    if (outSound == nullptr) {
        std::cerr << "Failed to load sound! Filepath: " << filePath
        << ". SDL_mixer Error: "<< Mix_GetError() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int32_t Media::createMusicFromFile(const char* filePath, Mix_Music*& outMusic) {
    outMusic = Mix_LoadMUS(filePath);
    if (outMusic == nullptr) {
        std::cerr << "Failed to load music! SDL_mixer Error: "
            << Mix_GetError() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void Media::freeSound(Mix_Chunk*& sound) {
    if (sound) {
        Mix_FreeChunk(sound);
        sound = nullptr;
    }
}

void Media::freeMusic(Mix_Music*& music) {
    if (music) {
        Mix_FreeMusic(music);
        music = nullptr;
    }
}
