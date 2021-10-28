#ifndef DRAWMGR_H
#define DRAWMGR_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>

/* Third-party icnludes */

/* Own icnludes */
#include "manager_utils/managers/MgrBase.h"
#include "sdl_utils/Monitor.h"
#include "sdl_utils/Renderer.h"

/* Forward Declaration */
struct DrawMgrConfig;

class DrawMgr : public MgrBase {
public:
	DrawMgr() = default;

	DrawMgr(const DrawMgr& other) = delete;
	DrawMgr(DrawMgr&& other) = delete;

	DrawMgr& operator=(const DrawMgr& other) = delete;
	DrawMgr& operator=(DrawMgr&& other) = delete;

	int32_t init(const DrawMgrConfig& config);

	void deinit() final;
	void process() final;

	void clearScreen();
	void finishFrame();
	void addDrawCmd(const DrawParams& drawParams);

	void setWidgetBlendMode(const DrawParams& drawParams, BlendMode blendMode);
	void setWidgetOpacity(const DrawParams& drawParams, int32_t opacity);

private:
	SDL_Texture* getTextureIntern(const DrawParams& drawParams) const;

	Monitor _window;
	Renderer _renderer;

	int64_t _maxFrames{ 0 };
};

extern DrawMgr* gDrawMgr;

#endif