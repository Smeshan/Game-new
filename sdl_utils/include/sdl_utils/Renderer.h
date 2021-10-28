#ifndef RENDERER_H
#define RENDERER_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>

/* Third-party icnludes */

/* Own icnludes */
#include "utils/drawing/DrawParams.h"

/* Forward Declaration */
struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Window;

class Renderer {
public:
	Renderer() = default;

	Renderer(const Renderer& other) = delete;
	Renderer(Renderer&& other) = delete;

	Renderer& operator=(const Renderer& other) = delete;
	Renderer& operator=(Renderer&& other) = delete;

	int32_t init(SDL_Window* window);
	void deinit();
	void clearScreen();
	void finishFrame();
	void renderTexture(SDL_Texture* texture, const DrawParams& drawParams);

	void setWidgetBlendMode(SDL_Texture* texture, BlendMode blendMode);
	void setWidgetOpacity(SDL_Texture* texture, int32_t opacity);

private:
	SDL_Renderer* _sdlRenderer = nullptr;
	void drawImage(const DrawParams& drawParams, SDL_Texture* texture);
	void drawText(const DrawParams& drawParams, SDL_Texture* texture);
};

#endif