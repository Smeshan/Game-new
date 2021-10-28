#ifndef IMAGECONTAINER_H
#define IMAGECONTAINER_H
/* C system icnludes */

/* C++ system icnludes */
#include <cstdint>
#include <unordered_map>

/* Third-party icnludes */
#include "utils/drawing/Rectangle.h"
#include "sdl_utils/config/ImageContainerConfig.h"

/* Own icnludes */

/* Forward Declaration */
struct SDL_Texture;

class ImageContainer {
public:

	SDL_Texture* getImageTexture(int32_t resId) const;
	Rectangle getImageFrame(int32_t resId) const;

protected:

	int32_t init(const ImageContainerConfig& configs);
	void deinit();

private:

	int32_t loadSingleResource(const ImageConfig& resConfig, const int32_t resId);

	std::unordered_map<int32_t, SDL_Texture*> _textures;
	std::unordered_map<int32_t, Rectangle> _textureFrames;
};
#endif