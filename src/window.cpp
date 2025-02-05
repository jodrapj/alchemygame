#include "window.h"
#include "window.h"

#include <iostream>
#include <SDL.h>

SDL_Window* Window::gWindow = NULL;
SDL_Surface* Window::gScreenSurface = NULL;
SDL_Surface* Window::gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
SDL_Surface* Window::gCurrentSurface = NULL;

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
    gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("res/press.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL) {
        std::cout << "ERROR" << std::endl;
        return 1;
    }

    //Load up surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("res/up.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL) {
        std::cout << "ERROR" << std::endl;
        return 1;
    }

    //Load down surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("res/down.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL) {
        std::cout << "ERROR" << std::endl;
        return 1;
    }

    //Load left surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("res/left.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL) {
        std::cout << "ERROR" << std::endl;
        return 1;
    }

    //Load right surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("res/right.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL) {
        std::cout << "ERROR" << std::endl;
        return 1;
    }

    return 0;
}

void Window::destroy() {

    for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i) {
        SDL_FreeSurface(gKeyPressSurfaces[i]);
        gKeyPressSurfaces[i] = NULL;
    }

	SDL_DestroyWindow(gWindow);

	SDL_Quit();
}

SDL_Surface* Window::loadSurface(std::string path) {
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL) {
		std::cout << "Unable to load image " << path << "! SDL_ERROR: " << SDL_GetError() << std::endl;
		return NULL;
	}

	return loadedSurface;
}
