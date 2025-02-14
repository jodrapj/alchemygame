#pragma once

#include <string>

struct SDL_Texture;
struct SDL_Renderer;

class Texture {
	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;
public:
	SDL_Renderer* gRenderer;

	Texture(SDL_Renderer* renderer);
	~Texture();
	int loadFromFile(std::string path);
	void free();
	void render(int x, int y);

	int getWidth();
	int getHeight();
};