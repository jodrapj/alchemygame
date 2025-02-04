
#include "SDL.h"
#include <iostream>

#include "alchemy.h"
#include "AlchemyObject.h"
#include "enums.h"
#include "Potion.h"
#include "namegen.h"
#include "window.h"
#include <SDL2/SDL_video.h>

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

int main() {

	Window::init("hello", 600, 800);
	Window::loadMedia();
	SDL_UpdateWindowSurface(Window::gWindow);

	SDL_Event e;
	bool quit = false;
	while (quit == false) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit == true;
			}
		}
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