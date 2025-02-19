#pragma once

struct SDL_Window;
struct SDL_Surface;
struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Point;
typedef enum SDL_RendererFlip;

class Entity;

class Window {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	Window(const char* p_title, int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filePath);
	void cleanUp();
	void clear();
	void render(Entity& p_entity, double angle, SDL_Point& center, SDL_RendererFlip flip);
	void display();
};