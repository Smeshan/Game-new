/* Corresponding header */
#include "manager_utils/managers/RsrcMgr.h"  

/* C system icnludes */

/* C++ system icnludes */
#include <iostream>

/* Third-party icnludes */

/* Own icnludes */
#include "manager_utils/config/RsrcMgrConfig.h"

RsrcMgr* gRsrcMgr = nullptr;

int32_t RsrcMgr::init(const RsrcMgrConfig& config) {
    if (EXIT_SUCCESS != ImageContainer::init(config.imageContainerConfig)) {
        std::cerr << "_imageContainer.init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    if (EXIT_SUCCESS != TextContainer::init(config.textContainerConfig)) {
        std::cerr << "_textContainer.init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void RsrcMgr::deinit() {
    TextContainer::deinit();
    ImageContainer::deinit();
}

void RsrcMgr::process() {

}


