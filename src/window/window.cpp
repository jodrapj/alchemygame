#include "window.h"
#include "window.h"
#include "window.h"
#include "window.h"
#include "window.h"
#include <SDL.h>
#include <SDL_image.h>

#include "window.h"

#include <iostream>

Window::Window(const char* p_title, int p_w, int p_h) : window(NULL), renderer(NULL) {
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
	
	if (window == NULL) {
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* Window::loadTexture(const char* p_filePath) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL) {
		std::cout << "Failed to load texture, Error: " << SDL_GetError() << std::endl;
	}

	return texture;
}

void Window::cleanUp() {
	SDL_DestroyWindow(window);
}

void Window::clear() {
	SDL_RenderClear(renderer);
}

void Window::render(SDL_Texture* p_tex) {
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = 32;
	src.h = 32;

	// destination
	SDL_Rect dst;
	dst.x = 0;
	dst.y = 0;
	dst.w = 32 * 4;
	dst.h = 32 * 4;

	SDL_RenderCopy(renderer, p_tex, &src, &dst);
}

void Window::display() {
	SDL_RenderPresent(renderer);
}
