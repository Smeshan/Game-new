/* Corresponding header */
#include "engine/EngineConfigLoader.h"

/* C system icnludes */

/* C++ system icnludes */
#include <string>
#include <unordered_map>

/* Third-party icnludes */

/* Own icnludes */
#include "utils/tools/ConfigApplier.h"
#include "utils/tools/ConfigExtractor.h"
#include "sdl_utils/tools/AutoResLoader.h"
#include "common/CommonDefines.h"
#include "utils/common/CommonPaths.h"

constexpr auto MAX_FRAME_RATE = 30;

typedef std::unordered_map<std::string, std::string> configData;

static void populateMonitorConfig(MonitorConfig& outConfig) {
    const configData data = ConfigExtractor::readFromFile(MONITOR_CFG_FILE);

    outConfig.windowName = ConfigApplier::applyConfig(data, WINDOW_NAME, STRING);
    outConfig.windowHeight = stoi(ConfigApplier::applyConfig(data, DISPLAY_HEIGHT, INT));
    outConfig.windowWidth = stoi(ConfigApplier::applyConfig(data, DISPLAY_WIDTH, INT));

    outConfig.windowFlags = WINDOW_SHOWN;
    //outConfig.windowFlags = WINDOW_FULLSCREEN;
}

// CONTAINERS
static void populateImageContainerConfig(ImageContainerConfig& cfg) {
    cfg.imageData = AutoResLoader::getFileConfigFromFolder();

    /* for (const auto& image : cfg.imageData) {
        std::cerr << "Current file info -> ID:" << image.id << " Name: "
            << image.name << " Location: " << image.location << " Width: "
            << image.width << " Height: " << image.height << std::endl;
    } */
}

static void populateTextContainerConfig(TextContainerConfig& cfg) {
    FontConfig fontConfig;
    fontConfig.location = FONT_FILE;
    fontConfig.fontSize = 40;
    cfg.fontConfigs.insert(std::make_pair(FontId::ANGELINE_VINTAGE, fontConfig));
}

static void populateSoundContainerConfig(SoundContainerConfig& cfg) {
    SoundConfig soundConfig;
    soundConfig.location = SOUND_FILE_PATH;
    soundConfig.length = 10;
    cfg.soundConfigs.insert(std::make_pair(MediaId::RING_SFX, soundConfig));
}

// MANAGERS
static void populateDrawMgrConfig(DrawMgrConfig& outConfig) {
    populateMonitorConfig(outConfig.windowConfig);
    outConfig.maxFrameRate = MAX_FRAME_RATE;
}

static void populateRsrcMgrConfig(RsrcMgrConfig& outConfig) {
    populateImageContainerConfig(outConfig.imageContainerConfig);
    populateTextContainerConfig(outConfig.textContainerConfig);
}

static void populateMediaMgrConfig(MediaMgrConfig& outConfig) {
    populateSoundContainerConfig(outConfig.soundContainerConfig);
}

static void populateManagerHandlerConfig(ManagerHandlerConfig& outConfig) {
    populateDrawMgrConfig(outConfig.drawMgrConfig);
    populateRsrcMgrConfig(outConfig.rsrcMgrConfig);
    populateMediaMgrConfig(outConfig.mediaMgrConfig);
}

// GAME
static void populateGameConfig(GameConfig& outConfig) {
    outConfig.layer2ResId = TextureId::LAYER_2;
    outConfig.pressKeysResId = TextureId::ALL_KEYS;
    outConfig.gameMapId = TextureId::GAMEMAP;

    outConfig.textFondId = FontId::ANGELINE_VINTAGE;

    outConfig.ringSFXId = MediaId::RING_SFX;

}


EngineConfig EngineConfigLoader::loadConfig() {
    EngineConfig cfg;
    populateManagerHandlerConfig(cfg.managerHandlerConfig);
    populateGameConfig(cfg.gameConfig);
    return cfg;
}
