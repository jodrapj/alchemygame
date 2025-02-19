#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <mathf.h>

class Entity {
private:
	Vector2f pos;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
	SDL_Point center;
	int lastDirection[4];
	SDL_RendererFlip flip;
public:
	Entity(Vector2f p_pos, SDL_Texture* p_tex);
	Vector2f& getPos() { return pos; }
	SDL_Texture* getTexture();
	SDL_Rect getCurrentFrame();
	SDL_Point& getCenter();
	SDL_RendererFlip getFlip();
	void update();
	int directions[4];
};