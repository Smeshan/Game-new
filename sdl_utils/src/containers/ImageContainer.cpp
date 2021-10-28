/* Corresponding header */
#include "sdl_utils/containers/ImageContainer.h"

/* C system icnludes */

/* C++ system icnludes */
#include <iostream>

/* Third-party icnludes */

/* Own icnludes */
#include "sdl_utils/Texture.h"

int32_t ImageContainer::init(const ImageContainerConfig& configs) {
    const size_t size = configs.imageData.size();
    for (int32_t id = 0; id < (int32_t)size; ++id) {
        const auto& element = configs.imageData[id];

        if (EXIT_SUCCESS != loadSingleResource(element, id)) {
            std::cerr << "loadSingleResource() failed for file: " << element.location
                << std::endl;
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

void ImageContainer::deinit() {
    for (auto& pair : _textures) {
        Texture::freeTexture(pair.second);
    }
}

SDL_Texture* ImageContainer::getImageTexture(int32_t resId) const {
    auto it = _textures.find(resId);
    if (it == _textures.end()) {
        std::cerr << "Error, invalid resId: " << resId << " requseted." << std::endl;
        return nullptr;
    }
    return it->second;
}

Rectangle ImageContainer::getImageFrame(int32_t resId) const {
    auto it = _textureFrames.find(resId);
    if (it == _textureFrames.end()) {
        std::cerr << "Error, invalid resId: " << resId
            << " requseted. Returning ZERO rectangle" << std::endl;
        return Rectangle::ZERO;
    }
    return it->second;
}

int32_t ImageContainer::loadSingleResource(const ImageConfig& resConfig, const int32_t resId) {
    SDL_Texture* texture = nullptr;
    if (EXIT_SUCCESS != Texture::createTextureFromFile(resConfig.location.c_str(), texture)) {
        std::cerr << "Texture::createTextureFromFile() failed for file: " << resConfig.location
            << std::endl;
        return EXIT_FAILURE;
    }
    _textures[resId] = texture;

    Rectangle& rect = _textureFrames[resId];
    rect.x = 0;
    rect.y = 0;
    rect.w = resConfig.width;
    rect.h = resConfig.height;

    return EXIT_SUCCESS;
}