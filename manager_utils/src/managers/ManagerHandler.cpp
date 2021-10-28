/* Corresponding header */
#include "manager_utils/managers/ManagerHandler.h"  

/* C system icnludes */

/* C++ system icnludes */
#include <iostream>

/* Third-party icnludes */

/* Own icnludes */
#include "manager_utils/config/ManagerHandlerConfig.h"
#include "manager_utils/managers/DrawMgr.h"
#include "manager_utils/managers/RsrcMgr.h"

int32_t ManagerHandler::init(const ManagerHandlerConfig& config) {
    gDrawMgr = new DrawMgr();
    if (gDrawMgr == nullptr) {
        std::cerr << "Erorr, bad alloc for DrawMgr" << std::endl;
        return EXIT_FAILURE;
    }

    if (EXIT_SUCCESS != gDrawMgr->init(config.drawMgrConfig)) {
        std::cerr << "gDrawMgr->init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    gRsrcMgr = new RsrcMgr();
    if (gRsrcMgr == nullptr) {
        std::cerr << "Erorr, bad alloc for gRsrcMgr" << std::endl;
        return EXIT_FAILURE;
    }

    if (EXIT_SUCCESS != gRsrcMgr->init(config.rsrcMgrConfig)) {
        std::cerr << "gRsrcMgr->init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    _managers[DRAW_MGR_INDX] = static_cast<MgrBase*>(gDrawMgr);
    _managers[RSRC_MGR_INDX] = static_cast<MgrBase*>(gRsrcMgr);

    return EXIT_SUCCESS;
}

void ManagerHandler::deinit() {
    for (int32_t i = MANAGERS_COUNT - 1; i >= 0; --i) {
        _managers[i]->deinit();
        _managers[i] = nullptr;
    }
}

void ManagerHandler::process() {
    for (int32_t i; i < MANAGERS_COUNT; ++i) {
        _managers[i]->process();
    }
}

void ManagerHandler::nullifyGlobalMgr(int32_t mgrIdx) {
    switch (mgrIdx) {
    case DRAW_MGR_INDX:
        delete gDrawMgr;
        gDrawMgr = nullptr;
        break;
    case RSRC_MGR_INDX:
        delete gRsrcMgr;
        gRsrcMgr = nullptr;
        break;
    default:
        std::cerr << "Recieved invalid mgrIdx: " << mgrIdx << std::endl;
        break;
    }
}
