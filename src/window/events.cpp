#include "events.h"

#include <SDL.h>

void keyDown(SDL_KeyboardEvent* event, int moveReqsts[]) {
	if (event->repeat == 0) {
		if (event->keysym.scancode == SDL_SCANCODE_UP) {
			moveReqsts[0] = 1;
		}
		if (event->keysym.scancode == SDL_SCANCODE_DOWN) {
			moveReqsts[1] = 1;
		}
		if (event->keysym.scancode == SDL_SCANCODE_LEFT) {
			moveReqsts[2] = 1;
		}
		if (event->keysym.scancode == SDL_SCANCODE_RIGHT) {
			moveReqsts[3] = 1;
		}
	}
}

void keyUp(SDL_KeyboardEvent* event, int moveReqsts[]) {
	if (event->repeat == 0) {
		if (event->keysym.scancode == SDL_SCANCODE_UP) {
			moveReqsts[0] = 0;
		}
		if (event->keysym.scancode == SDL_SCANCODE_DOWN) {
			moveReqsts[1] = 0;
		}
		if (event->keysym.scancode == SDL_SCANCODE_LEFT) {
			moveReqsts[2] = 0;
		}
		if (event->keysym.scancode == SDL_SCANCODE_RIGHT) {
			moveReqsts[3] = 0;
		}
	}
}

void Events::init() {

}

void Events::handler(int moveReqsts[]) {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			keyDown(&event.key, moveReqsts);
		}
		if (event.type == SDL_KEYUP) {
			keyUp(&event.key, moveReqsts);
		}
	}
}