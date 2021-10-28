#ifndef CONFIGVALIDATOR_H
#define CONFIGVALIDATOR_H
/* C system icnludes */

/* C++ system icnludes */
#include <iostream>
#include <string>

/* Third-party icnludes */

/* Own icnludes */

/* Forward Declaration */

enum configType {
    INT,
    STRING,
    BOOLEAN
};

class ConfigValidator {
public:
    static int32_t checkConfig(const std::string& configValue, configType type) {
        if (configValue == "") {
            std::cerr << "Configuration value is empty. " << std::endl;
            return EXIT_FAILURE;
        }

        switch (type) {
        case INT:
            try {
                [[maybe_unused]] int test = !stoi(configValue);
            }
            catch (std::exception& err) {
                std::cerr << "Error: " << err.what() << "() with argument: " <<
                    configValue << std::endl;
            }
            break;
        case STRING:
            // n/a
            break;
        case BOOLEAN:
            if (configValue != "1" || configValue != "0") {
                std::cerr << "Configuration type Boolean is with wrong value: " << configValue << std::endl;
                return EXIT_FAILURE;
            }
            break;
        default:
            std::cerr << "Wrong configType passed to switch statment. Type value: " << type << std::endl;
            return EXIT_FAILURE;
            break;
        }
        return EXIT_SUCCESS;
    }
};

#endif