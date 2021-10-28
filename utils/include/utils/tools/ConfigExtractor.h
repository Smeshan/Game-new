#ifndef CONFIGEXTRACTOR_H
#define CONFIGEXTRACTOR_H

/* C system icnludes */

/* C++ system icnludes */
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

/* Third-party icnludes */

/* Forward Declaration */

typedef std::unordered_map<std::string, std::string> configData;

struct ConfigExtractor {
public:
    static configData readFromFile(const std::string& filePath) {
        configData data;
        std::fstream file(filePath);
        if (!file.is_open()) {
            std::cerr << "Unable to open config file: " << filePath << std::endl;
        }
        std::string configName, configValue;
        while (!file.eof()) { // eof -> end of file
            getline(file, configName, ':');
            getline(file, configValue);
            data[configName] = configValue;
        }
        file.close();
        return data;
    }

private:
};

#endif