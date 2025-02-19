#pragma once

#include <SDL.h>

class Entity;

class EventHandler {
	SDL_Event event;
	void keyDown(Entity& ent);
	void keyUp(Entity& ent);
public:
	EventHandler();
	int handle(Entity& controlledEntity);
};