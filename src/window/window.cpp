#include "window.h"
#include "window.h"
#include "window.h"

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

SDL_Window* Window::window = NULL;
SDL_Surface* Window::screenSurface = NULL;
SDL_Texture* Window::texture = NULL;
SDL_Renderer* Window::renderer = NULL;

int Window::width = 0;
int Window::height = 0;

int Window::init(const char* title, int width, int height) {
	int rendererFlags, windowFlags;
	
	Window::width = width;
	Window::height = height;

	rendererFlags = SDL_RENDERER_ACCELERATED;
	windowFlags = 0;

	// SDL Initialization
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not initialize! SDL_ERROR: " << SDL_GetError() << std::endl;
		return 1;
	}

	// Window creation
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, windowFlags);
	if (window == NULL) {
		std::cout << "Window could not be created! SDL_ERROR: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, rendererFlags);
	if (renderer == NULL) {
		std::cout << "Renderer coult not be created! SDL_ERROR: " << SDL_GetError() << std::endl;
		return 1;
	}

	// Set renderer(background) color to white
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
		return 1;
	}

	return 0;
}

void Window::destroy() {

	SDL_DestroyTexture(texture);
	texture = NULL;

	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Window::loadTexture(std::string path) {
	SDL_Texture* texture;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", path.c_str());

	texture = IMG_LoadTexture(renderer, path.c_str());

	return texture;
}

void Window::blit(SDL_Texture* texture, int x, int y) {
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(renderer, texture, NULL, &dest);
}
