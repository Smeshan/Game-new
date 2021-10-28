/* Corresponding header */
#include "sdl_utils/Renderer.h"

/* C system icnludes */

/* C++ system icnludes */
#include <iostream>

/* Third-party icnludes */
#include <SDL_hints.h>
#include <SDL_render.h>

/* Own icnludes */
#include "sdl_utils/Texture.h"

int32_t Renderer::init(SDL_Window* window) {
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        std::cerr << "Warning: Linear texture filtering not enabled! "
            "SDL_SetHint() failed. SDL Error:"
            << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    constexpr auto driverId = -1; // -1 for unspecified
    _sdlRenderer = SDL_CreateRenderer(window, driverId, SDL_RENDERER_ACCELERATED);
    if (_sdlRenderer == nullptr) {
        std::cerr << "SDL_CreateRenderer() failed. Reason: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    constexpr auto red = 0;
    constexpr auto green = 0;
    constexpr auto blue = 0;
    constexpr auto alpha = SDL_ALPHA_OPAQUE;
    if (EXIT_SUCCESS != SDL_SetRenderDrawColor(_sdlRenderer, red, green, blue, alpha)) {
        std::cerr << "SDL_SetRenderDrawColor() failed" << std::endl;
        return EXIT_FAILURE;
    }

    Texture::setRenderer(_sdlRenderer);

    return EXIT_SUCCESS;
}

void Renderer::deinit() {
    if (!_sdlRenderer) {
        SDL_DestroyRenderer(_sdlRenderer);
    }
}

void Renderer::clearScreen() {
    if (EXIT_SUCCESS != SDL_RenderClear(_sdlRenderer)) {
        std::cerr << "SDL_RenderClear() failed" << std::endl;
    }
}

void Renderer::finishFrame() {
    SDL_RenderPresent(_sdlRenderer);
}

void Renderer::renderTexture(SDL_Texture* texture, const DrawParams& drawParams) {
    if (WidgetType::IMAGE == drawParams.widgetType) {
        drawImage(drawParams, texture);
    }
    else if (WidgetType::TEXT == drawParams.widgetType) {
        drawText(drawParams, texture);
    }
    else {
        std::cerr << "Error, recieved unsupported WidgetType: " <<
            static_cast<int32_t>(drawParams.widgetType) <<
            "for resId: " << drawParams.resId << std::endl;
    }
}

void Renderer::setWidgetBlendMode(SDL_Texture* texture, BlendMode blendMode) {
    if (EXIT_SUCCESS != Texture::setBlendModeTexture(texture, blendMode)) {
        std::cerr << "Texture::setBlendModeTexture() failed." << std::endl;
    }
}

void Renderer::setWidgetOpacity(SDL_Texture* texture, int32_t opacity) {
	if (EXIT_SUCCESS != Texture::setAlphaTexture(texture, opacity)) {
        std::cerr << "Texture::setAlpaTexture() failed." << std::endl;
    }
}

void Renderer::drawImage(const DrawParams& drawParams, SDL_Texture* texture) {
    const SDL_Rect destRect = { .x = drawParams.pos.x, .y = drawParams.pos.y,
                                .w = drawParams.width, .h = drawParams.height };

    int32_t err = EXIT_SUCCESS;
    if (FULL_OPACITY != drawParams.opacity) {
        err = SDL_RenderCopy(_sdlRenderer, texture, nullptr, &destRect);
    }
    else {
        if (EXIT_SUCCESS != Texture::setAlphaTexture(texture, drawParams.opacity)) {
            std::cerr << "Texture::setAlphaTexture() failed for resID: "
                << drawParams.resId << std::endl;
        }
        err = SDL_RenderCopy(_sdlRenderer, texture, nullptr, &destRect);

        if (EXIT_SUCCESS != Texture::setAlphaTexture(texture, FULL_OPACITY)) {
            std::cerr << "Texture::setAlphaTexture() failed for resID: "
                << drawParams.resId << std::endl;
        }
    }
    if (EXIT_SUCCESS != err) {
        std::cerr << "SDL_RenderCopy() failed for resID: " << drawParams.resId
            << ". Reason: " << SDL_GetError() << std::endl;
    }
}

void Renderer::drawText(const DrawParams& drawParams, SDL_Texture* texture) {
    const SDL_Rect destRect = { .x = drawParams.pos.x, .y = drawParams.pos.y,
                                .w = drawParams.width, .h = drawParams.height };

    int32_t err = SDL_RenderCopy(_sdlRenderer, texture, nullptr, &destRect);

    if (EXIT_SUCCESS != err) {
        std::cerr << "SDL_RenderCopy() failed for resID: " << drawParams.resId
            << ". Reason: " << SDL_GetError() << std::endl;
    }


}