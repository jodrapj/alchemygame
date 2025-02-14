#include <iostream>

#include "SDL.h"
#include "alchemy.h"
#include "Alchemy/AlchemyObject.h"
#include "enums.h"
#include "Alchemy/Potion.h"
#include "namegen.h"
#include "window/window.h"
#include "entity.h"
#include "window/events.h"
#include <numeric>

Effects randomeffect(NameGen* gen) {
	int a = gen->random(0, 2);
	switch (a) {
	case 0:
		return ALCOHOL;
		break;
	case 1:
		return HEAL;
		break;
	case 2:
		return DAMAGE;
		break;
	}
}

int main(int argc, char* argv[]) {

	Window::init("alchemygame", 1280, 720);

	Entity player;
	player.x = 1;
	player.y = 1;
	player.texture = Window::loadTexture("res/textures/player.png");

	float normalY = (Window::height / (Window::height / 2)) - 1;
	float normalX = (Window::width / (Window::width / 2)) - 1;

	int moveReq[4];
	for (int i = 0; i < 3; i++) {
		moveReq[i] = 0;
	}

	while (1) {
		SDL_SetRenderDrawColor(Window::renderer, 96, 128, 255, 255);
		SDL_RenderClear(Window::renderer);
		Events::handler(moveReq);

		if (moveReq[0]) {
			player.y -= 4;
		}
		if (moveReq[1]) {
			player.y += 4;
		}
		if (moveReq[2]) {
			player.x -= 4;
		}
		if (moveReq[3]) {
			player.x += 4;
		}

		std::cout << "Plr X: " << player.x << " Plr y" << player.y << " X normal: " << normalX << " Y normal " << normalY << std::endl;
		
		Window::blit(player.texture, player.x * 2, player.y * 2);
		SDL_RenderPresent(Window::renderer);
		SDL_Delay(16);
	}

	return 0;
}

void testGen() {

	// TEST STAGE
	NameGen* gen = new NameGen();

	// Generate 10 random ingredients
	for (int i = 0; i < 10; i++) {
		AlchemyObject* obj = new AlchemyObject(randomeffect(gen), PLANT, i, false, gen->generateName());
		Alchemy::ingredients[obj] = 10;
	}

	//Generate 10 random potions using random ingredients
	for (int i = 0; i < 10; i++) {

		std::map<AlchemyObject*, unsigned int>::iterator it2;
		for (it2 = Alchemy::ingredients.begin(); it2 != Alchemy::ingredients.end(); it2++) {
			int rnd = gen->random(0, 2);
			if (rnd == 1)
				Alchemy::addIngredient(it2->first);
		}

		Alchemy::mix(gen);
	}

	std::cout << "Current ingredients:\n";
	std::map<AlchemyObject*, unsigned int>::iterator it;
	for (it = Alchemy::ingredients.begin(); it != Alchemy::ingredients.end(); it++) {
		std::cout << it->first->name << " Quantity: " << it->second << " Intensity: " << it->first->intensity << " Effect: " << it->first->effect << "\n";
	}

	std::cout << std::endl;

	std::cout << "Current potions:\n";
	std::map<Potion*, unsigned int>::iterator it1;
	for (it1 = Alchemy::potions.begin(); it1 != Alchemy::potions.end(); it1++) {
		std::cout << "Potion: " << it1->first->name << " Quantity: " << it1->second << " Intensity: " << it1->first->intensity << " ";
		
		std::map<Effects, unsigned int>::iterator it3;
		for (it3 = it1->first->effect.begin(); it3 != it1->first->effect.end(); it3++) {
			std::cout << "Effect: " << it3->first << " Quantity: " << it3->second << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

}