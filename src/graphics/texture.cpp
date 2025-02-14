#include "texture.h"

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

Texture::Texture(SDL_Renderer* renderer) : mTexture(NULL), mWidth(0), mHeight(0), gRenderer(renderer) {}

Texture::~Texture() {
	free();
}

int Texture::loadFromFile(std::string path) {
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		std::cout << "Unable to load image " << path << " SDL_image error: " << IMG_GetError() << std::endl;
		return 1;
	}

	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

	newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
	mWidth = loadedSurface->w;
	mHeight = loadedSurface->h;
	SDL_FreeSurface(loadedSurface);

	mTexture = newTexture;

	return mTexture != NULL;
}

void Texture::free() {
	if (mTexture != NULL) {
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Texture::render(int x, int y) {
	SDL_Rect renderQuad = { x,y,mWidth,mHeight };
	SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad);
}

int Texture::getWidth() {
	return mWidth;
}

int Texture::getHeight() {
	return mHeight;
}

