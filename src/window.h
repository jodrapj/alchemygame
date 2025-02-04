#pragma once

struct SDL_Window;
struct SDL_Surface;

namespace Window {
	extern SDL_Window* gWindow;
	extern SDL_Surface* gScreenSurface;
	extern SDL_Surface* gHelloWorld;

	int width, height;

	int init(const char* title, int width, int height);
	int loadMedia();
	void destroy();
}