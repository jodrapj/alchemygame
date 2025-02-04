#include "window.h"

#include <iostream>
#include <SDL.h>

int Window::init(const char* title, int width, int height) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not initialize! SDL_ERROR: " << SDL_GetError() << std::endl;
		return 1;
	}

	gWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (gWindow == NULL) {
		std::cout << "Window could not be created! SDL_ERROR: " << SDL_GetError() << std::endl;
		return 1;
	}

	gScreenSurface = SDL_GetWindowSurface(gWindow);

	return 0;
}

int Window::loadMedia() {
	gHelloWorld = SDL_LoadBMP("res/testimg.bmp");
	if (gHelloWorld == NULL) {
		std::cout << "Unable to load image! SDL_ERROR: " << SDL_GetError() << std::endl;
		return 1;
	}

	return 0;
}

void Window::destroy() {
	SDL_FreeSurface(gHelloWorld);
	SDL_DestroyWindow(gWindow);

	SDL_Quit();
}
