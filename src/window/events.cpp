#include "events.h"

#include <iostream>
#include "entity.h"

void EventHandler::keyDown(Entity& ent) {
	switch (event.key.keysym.sym) {
	case SDLK_UP:
		ent.directions[0] = 1;
		break;
	case SDLK_LEFT:
		ent.directions[1] = 1;
		break;
	case SDLK_DOWN:
		ent.directions[2] = 1;
		break;
	case SDLK_RIGHT:
		ent.directions[3] = 1;
	default:
		break;
	}
}

void EventHandler::keyUp(Entity& ent) {
	switch (event.key.keysym.sym) {
	case SDLK_UP:
		ent.directions[0] = 0;
		break;
	case SDLK_LEFT:
		ent.directions[1] = 0;
		break;
	case SDLK_DOWN:
		ent.directions[2] = 0;
		break;
	case SDLK_RIGHT:
		ent.directions[3] = 0;
	default:
		break;
	}
}

// later for keybinds initialization
EventHandler::EventHandler() {
}

int EventHandler::handle(Entity& controlledEntity) {
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			keyDown(controlledEntity);
			break;
		case SDL_KEYUP:
			keyUp(controlledEntity);
			break;
		case SDL_QUIT:
			return 1;
		}
	}

	return 0;
}
