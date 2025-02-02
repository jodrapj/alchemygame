#pragma once

#include <map>
#include <vector>
#include <string>

class AlchemyObject;
class Potion;
class NameGen;

namespace Alchemy {
	extern std::map<Potion*, unsigned int> potions;
	extern std::map<AlchemyObject*, unsigned int> ingredients;
	extern std::map<AlchemyObject*, unsigned int> usedIngredients;

	void addIngredient(AlchemyObject* ingredient);
	void mix(NameGen* gen);
	void emptyCauldron();
}