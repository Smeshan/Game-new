/* Corresponding header */
#include "game/entities/KeyWords.h"  

/* C system icnludes */

/* C++ system icnludes */

/* Third-party icnludes */

/* Own icnludes */

bool KeyWords::checkForKeyWord(const std::string& word) {
    for (const auto& keyWord : KEY_WORDS) {
        if (keyWord == word) {
            return true;
        }
    }
    return false;
}
