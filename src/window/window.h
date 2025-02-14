#pragma once

#include <string>

struct SDL_Window;
struct SDL_Surface;
struct SDL_Renderer;
struct SDL_Texture;

namespace Window {
	extern SDL_Window* window;
	extern SDL_Surface* screenSurface;
	extern SDL_Renderer* renderer;
	extern SDL_Texture* texture;

	extern int width;
	extern int height;

	int init(const char* title, int width, int height);
	void destroy();

	SDL_Texture* loadTexture(std::string path);
	void blit(SDL_Texture* texture, int x, int y);
}