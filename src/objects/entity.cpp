#include "entity.h"

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex)
	: pos(p_pos), tex(p_tex), flip(SDL_FLIP_NONE)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;

	center.x = currentFrame.w / 2;
	center.y = currentFrame.y / 2;
	
	for (int i = 0; i < 4; i++) {
		directions[i] = 0;
		lastDirection[i] = 0;
	}
}

SDL_Texture* Entity::getTexture() {
	return tex;
}

SDL_Rect Entity::getCurrentFrame() {
	return currentFrame;
}

SDL_Point& Entity::getCenter() {
	return center;
}

SDL_RendererFlip Entity::getFlip() {
	return flip;
}

void Entity::update() {

	if (directions[0] == 1) {
		pos.y -= 2;
		lastDirection[0] = directions[0];
	}
	if (directions[1] == 1) {
		pos.x -= 2;
		lastDirection[1] = directions[1];
		flip = SDL_FLIP_HORIZONTAL;
	}
	if (directions[2] == 1) {
		pos.y += 2;
		lastDirection[2] = directions[2];
	}
	if (directions[3] == 1) {
		pos.x += 2;
		lastDirection[3] = directions[3];
		flip = SDL_FLIP_NONE;
	}
}