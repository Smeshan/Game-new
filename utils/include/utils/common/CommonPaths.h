#ifndef COMMONPATHS_H
#define COMMONPATHS_H
/* C system icnludes */

/* C++ system icnludes */
#include <string>

/* Third-party icnludes */

/* Own icnludes */

/* Forward Declaration */

static std::string getFilePath(const std::string& path) {
    const std::string parentFolder = "../";
#ifdef RELEASE_BUILD
    return path;
#else
    return parentFolder + path;
#endif
}

const std::string RES_FOLDER_PATH = getFilePath("resources/images/");
const std::string FONT_FILE = getFilePath("resources/fonts/terminal.ttf");

const std::string MONITOR_CFG_FILE = "../sdl_utils/include/sdl_utils/config/MonitorConfig.txt";

const std::string SOUND_FILE_PATH = "../resources/sounds/sound.wav";
const std::string SINGLE_KEY_TYPE_PATH = "../resources/sounds/single_key_type.wav";

const std::string MUSIC_FILE_PATH = "resources/music/music.mp3";


#endif // COMMONPATHS_H