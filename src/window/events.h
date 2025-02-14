#pragma once

#include <SDL.h>

namespace Events {
	void init();
	void handler(int moveReqsts[]);
	//int keyDown(SDL_KeyboardEvent* event, int moveReqsts[]);
	//int keyUp(SDL_KeyboardEvent* event, int moveReqsts[]);
}