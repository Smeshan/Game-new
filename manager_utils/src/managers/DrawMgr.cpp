/* Corresponding header */
#include "manager_utils/managers/DrawMgr.h"  

/* C system icnludes */

/* C++ system icnludes */
#include <iostream>

/* Third-party icnludes */

/* Own icnludes */
#include "manager_utils/config/DrawMgrConfig.h"
#include "manager_utils/managers/RsrcMgr.h"

DrawMgr* gDrawMgr = nullptr;

int32_t DrawMgr::init(const DrawMgrConfig& config) {

    if (EXIT_SUCCESS != _window.init(config.windowConfig)) {
        std::cerr << "_window.init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    if (EXIT_SUCCESS != _renderer.init(_window.getWindow())) {
        std::cerr << "_render.init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void DrawMgr::deinit() {
    _renderer.deinit();
    _window.deinit();
}

void DrawMgr::process() {

}

void DrawMgr::clearScreen() {
    _renderer.clearScreen();
}

void DrawMgr::finishFrame() {
    _renderer.finishFrame();
}

void DrawMgr::addDrawCmd(const DrawParams& drawParams) {
     SDL_Texture* texture = getTextureIntern(drawParams);
    _renderer.renderTexture(texture, drawParams);
}

SDL_Texture* DrawMgr::getTextureIntern(const DrawParams& drawParams) const {
    if (WidgetType::IMAGE == drawParams.widgetType) {
        return gRsrcMgr->getImageTexture(drawParams.resId);
    }
    else if (WidgetType::TEXT == drawParams.widgetType) {
        return gRsrcMgr->getTextTexture(drawParams.textId);
    }
    else {
        std::cerr << "Error, recieved unsupported WidgetType: " 
                  << static_cast<int32_t>(drawParams.widgetType) 
                  << "for resId: " << drawParams.resId << std::endl;
    }
    return nullptr;
}


void DrawMgr::setWidgetBlendMode(const DrawParams& drawParams, BlendMode blendMode) {
    SDL_Texture* texture = getTextureIntern(drawParams);
    _renderer.setWidgetBlendMode(texture, blendMode);
}

void DrawMgr::setWidgetOpacity(const DrawParams& drawParams, int32_t opacity) {
    if (drawParams.widgetType == WidgetType::IMAGE) {
        return;
    }
	  SDL_Texture* texture = getTextureIntern(drawParams);
    _renderer.setWidgetOpacity(texture, opacity);
}