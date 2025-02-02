#include "alchemy.h"
#include "AlchemyObject.h"
#include "enums.h"
#include "Potion.h"
#include "namegen.h"

#include <iostream>

int main() {

	NameGen* gen = new NameGen();

	for (int i = 0; i < 10; i++) {
		AlchemyObject* obj = new AlchemyObject(ALCOHOL, PLANT, i, false, gen->generateName());
		Alchemy::ingredients[obj] = 10;
	}
	
	for (int i = 0; i < 10; i++) {

		std::map<AlchemyObject*, unsigned int>::iterator it2;
		for (it2 = Alchemy::ingredients.begin(); it2 != Alchemy::ingredients.end(); it2++) {
			int rand = gen->random(1, 15);

			if (rand == gen->random(1,15)) {
				Alchemy::addIngredient(it2->first);
			}
		}

		Alchemy::mix(gen);
	}

	std::cout << "Current ingredients:\n";
	std::map<AlchemyObject*, unsigned int>::iterator it;
	for (it = Alchemy::ingredients.begin(); it != Alchemy::ingredients.end(); it++) {
		std::cout << it->first->name << " " << it->second << "\n";
	}

	std::cout << std::endl;

	std::cout << "Current potions:\n";
	std::map<Potion*, unsigned int>::iterator it1;
	for (it1 = Alchemy::potions.begin(); it1 != Alchemy::potions.end(); it1++) {
		std::cout << "Potion: " << it1->first->name << " " << it1->second << "\n";
	}

	std::cout << std::endl;

	return 0;
}