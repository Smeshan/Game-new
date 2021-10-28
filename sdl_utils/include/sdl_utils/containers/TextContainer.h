#ifndef TEXTCONTAINER_H
#define TEXTCONTAINER_H
/* C system icnludes */

/* C++ system icnludes */
#include <vector>
#include <unordered_map>

/* Third-party icnludes */

/* Own icnludes */
#include "sdl_utils/config/TextContainerConfig.h"

/* Forward Declaration */
struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;
struct Color;

class TextContainer {
public:
	void createText(const char* text, const Color& color, int32_t fontId,
		int32_t& outTextId, int32_t& outTextWidth,
		int32_t& outTextHeight);

	void reloadText(const char* text, const Color& color, int32_t fontId,
		int32_t textId, int32_t& outTextWidth,
		int32_t& outTextHeight);

	void unloadText(int32_t textId);

	SDL_Texture* getTextTexture(int32_t textId) const;

protected:

	int32_t init(const TextContainerConfig& config);

	void deinit();


private:
	void occupyFreeSlotIndex(int32_t& outIndex, SDL_Texture* texture);
	void freeSlotIndex(int32_t index);

	std::vector<SDL_Texture*> _textures;
	std::unordered_map<int32_t, TTF_Font*> _fonts;
};
#endif