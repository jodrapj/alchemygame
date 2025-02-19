#include "window.h"

#include <SDL.h>
#include <SDL_image.h>

#include "entity.h"
#include <iostream>

Window::Window(const char* p_title, int p_w, int p_h) : window(NULL), renderer(NULL) {
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
	
	if (window == NULL) {
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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

void Window::render(Entity& p_entity, double angle, SDL_Point& center, SDL_RendererFlip flip) {
	SDL_Rect src;
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	// destination
	SDL_Rect dst;
	dst.x = p_entity.getPos().x;
	dst.y = p_entity.getPos().y;
	dst.w = p_entity.getCurrentFrame().w * 4;
	dst.h = p_entity.getCurrentFrame().h * 4;

	SDL_RenderCopyEx(renderer, p_entity.getTexture(), &src, &dst, angle, &center, flip);
}

void Window::display() {
	SDL_RenderPresent(renderer);
}
