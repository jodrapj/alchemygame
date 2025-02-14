#pragma once

class SDL_Texture;

class Entity {
public:
	int x;
	int y;
	SDL_Texture* texture;

	Entity(int x, int y, SDL_Texture* texture);
	Entity(int x, int y);
	Entity();
};