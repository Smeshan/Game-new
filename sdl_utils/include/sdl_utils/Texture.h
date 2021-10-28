#ifndef SDL_UTILS_TEXTURE_H_
#define SDL_UTILS_TEXTURE_H_

/* C system icnludes */

/* C++ system icnludes */
#include <cstdlib>

/* Third-party icnludes */

/* Own icnludes */
#include "utils/drawing/DrawParams.h"

/* Forward Declaration */
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;
typedef struct _TTF_Font TTF_Font;
struct Color;

class Texture {
public:
	Texture() = delete;
	~Texture();

	static int32_t createSurfaceFromFile(const char* filePath, SDL_Surface*& outSurface);
	static int32_t createTextureFromFile(const char* filePath, SDL_Texture*& outTexture);
	static int32_t createTextureFromSurface(SDL_Surface*& inOutSurface, SDL_Texture*& outTexture);
	static int32_t createTextureFromText(const char* text, const Color& color, TTF_Font* font,
		SDL_Texture*& outTexture, int32_t& outTextWidth, int32_t& outTextHeight);

	static void freeSurface(SDL_Surface*& surface);
	static void freeTexture(SDL_Texture*& texture);

	static void setRenderer(SDL_Renderer* renderer);

	static int32_t setBlendModeTexture(SDL_Texture* texture, BlendMode blendMode);

	static int32_t setAlphaTexture(SDL_Texture* texture, int32_t alpha);
};

#endif /* SDL_UTILS_TEXTURE_H_ */
