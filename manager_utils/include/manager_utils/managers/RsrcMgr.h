#ifndef RSRCMGR_H
#define RSRCMGR_H
/* C system icnludes */

/* C++ system icnludes */

/* Third-party icnludes */

/* Own icnludes */
#include "manager_utils/managers/MgrBase.h"
#include "sdl_utils/containers/ImageContainer.h"
#include "sdl_utils/containers/TextContainer.h"

/* Forward Declaration */
struct RsrcMgrConfig;

class RsrcMgr : public MgrBase,
				public ImageContainer,
				public TextContainer {
public:
	RsrcMgr() = default;

	RsrcMgr(const RsrcMgr& other) = delete;
	RsrcMgr(RsrcMgr&& other) = delete;

	RsrcMgr& operator=(const RsrcMgr& other) = delete;
	RsrcMgr& operator=(RsrcMgr&& other) = delete;

	int32_t init(const RsrcMgrConfig& config);

	void deinit() final;
	void process() final;



private:
	ImageContainer _imageContainer;
	TextContainer _textContainer;
};

extern RsrcMgr* gRsrcMgr;

#endif