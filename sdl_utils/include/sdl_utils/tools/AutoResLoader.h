#ifndef AUTORESLOADER_H
#define AUTORESLOADER_H

/* C system icnludes */
#include <dirent.h>

/* C++ system icnludes */
#include <vector>
#include <string>

/* Third-party icnludes */

/* Own icnludes */
#include "utils/common/CommonPaths.h"

/* Forward Declaration */
struct ImageConfig;

struct AutoResLoader {
public:
	static std::vector<ImageConfig> getFileConfigFromFolder();
};
#endif