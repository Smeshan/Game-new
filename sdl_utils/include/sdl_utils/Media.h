#ifndef MEDIA_H
#define MEDIA_H
/* C system icnludes */

/* C++ system icnludes */

/* Third-party icnludes */
#include <SDL_mixer.h>

/* Own icnludes */

/* Forward Declaration */

class Media {
public:
	Media() = delete;
	~Media();

	static int32_t createSoundFromFile(const char* filePath, Mix_Chunk*& outSound);
	static int32_t createMusicFromFile(const char* filePath, Mix_Music*& outMusic);

	static void freeSound(Mix_Chunk*& sound);
	static void freeMusic(Mix_Music*& music);


};
#endif