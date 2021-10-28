#ifndef CONFIGAPPLIER_H
#define CONFIGAPPLIER_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>

/* Third-party icnludes */

/* Own icnludes */
#include "utils/tools/ConfigValidator.h"

/* Forward Declaration */

struct ConfigApplier {
public:
    static std::string applyConfig(const configData &data, displayConfig name, configType type) {

        const std::string configName = displayConfigStr[name];

        auto it = data.find(configName);
        if (it == data.end()) {
            std::cerr << "There is no " << configName << " in the configurations data." << std::endl;
        }
        const std::string configValue = it->second;
        if (EXIT_SUCCESS != ConfigValidator::checkConfig(configValue, type)) {
            std::cerr << "Validation of config data failed." << std::endl;
        }
        return configValue;
    }
};
#endif