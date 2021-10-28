/* Corresponding header */
#include "sdl_utils/tools/AutoResLoader.h"

/* C system icnludes */

/* C++ system icnludes */
#include <sstream>
#include <iostream>
#include <cstdint>

/* Third-party icnludes */

/* Own icnludes */
#include "sdl_utils/config/ImageContainerConfig.h"
#include "utils/tools/ConfigValidator.h"

ImageConfig getWidthAndHeight(const std::string& file) {
    // File name pattern [NAME][_][ID][_][WIDTH][_][HEIGHT]
    ImageConfig info;
    std::string tempStr;

    std::istringstream istr(file);
    getline(istr, info.name, '_');

    getline(istr, tempStr, '_');
    ConfigValidator::checkConfig(tempStr, INT);
    info.id = std::stoi(tempStr);

    getline(istr, tempStr, '_');
    ConfigValidator::checkConfig(tempStr, INT);
    info.width = std::stoi(tempStr);

    getline(istr, tempStr, '.');
    ConfigValidator::checkConfig(tempStr, INT);
    info.height = std::stoi(tempStr);

    //getline(istr, config.type);

    return info;
}

std::vector<ImageConfig> AutoResLoader::getFileConfigFromFolder() {
    DIR* dir;
    dirent* file;
    if ((dir = opendir(RES_FOLDER_PATH.c_str())) == nullptr) {
        std::cerr << "Could not open resource directory: "
            << RES_FOLDER_PATH << std::endl;
    }

    //TODO fix RESOURCES COUNT
    std::vector<ImageConfig> imageData(4);
    while ((file = readdir(dir)) != nullptr) {
        const std::string currFile = file->d_name;
        if (currFile == "." || currFile == "..") {
            continue;
        }
        ImageConfig currImageConfig = getWidthAndHeight(currFile);
        currImageConfig.location = RES_FOLDER_PATH + currFile;

        imageData[currImageConfig.id] = currImageConfig;
    }

    closedir(dir);
    return imageData;
}