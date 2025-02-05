#pragma once

#include <string>

enum KeyPressSurfaces {
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

struct SDL_Window;
struct SDL_Surface;

namespace Window {
	extern SDL_Window* gWindow;
	extern SDL_Surface* gScreenSurface;
	extern SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
	extern SDL_Surface* gCurrentSurface;

	extern int width;
	extern int height;

	int init(const char* title, int width, int height);
	int loadMedia();
	void destroy();

	SDL_Surface* loadSurface(std::string path);
}