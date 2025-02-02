#include "namegen.h"

#include <random>

#include "AlchemyObject.h"
#include "Potion.h"
#include "mathf.h"

std::map<unsigned int, std::string> NameGen::alchemicIngredientNames = {
	{0, "Black"},
	{1, "White"},
	{2, "Blood-red"},
	{3, "God's"},
	{4, "Blood"},
	{5, "Bleeding"},
	{6, "Bittersweet"},
	{7, "Adder's"},
	{8, "Aconite"},
	{9, "Agapanthus"},
	{10, "Apple"},
	{11, "Mycos"},
	{12, "Artichoke"},
	{13, "Spider"},
	{14, "Aromatic"},
	{15, "August"},
	{16, "Bachelor's"},
	{17, "Balloon"},
	{18, "Bee"},
	{19, "Bighead"},
	{20, "Butterfly"}
};
std::map<unsigned int, std::string> NameGen::alchemicIngredientTypes = {
	{0, "Needle"},
	{1, "Lily"},
	{2, "Flame"},
	{3, "Boxwood"},
	{4, "Blossom"},
	{5, "Ash"},
	{6, "Adonis"},
	{7, "Majus"},
	{8, "Plume"},
	{9, "Thistle"},
	{10, "Aster"},
	{11, "Flower"},
	{12, "Breath"},
	{13, "Button"},
	{14, "Balm"},
	{15, "Rose"},
	{16, "Knapweed"},
	{17, "Ambrosia"},
	{18, "Susan"},
	{19, "Root"},
	{20, "Iris"},
};

std::map<unsigned int, std::string> NameGen::potionName = {
	
};

std::map<std::pair<std::string, Effects>, float> NameGen::potionPotencyEffectName = {

	// ALCOHOL effect
	{{"Weak beer", ALCOHOL}, 0},
	{{"Beer", ALCOHOL}, 1},
	{{"Liquor", ALCOHOL}, 2},
	{{"Vodka", ALCOHOL}, 3},
	{{"Moonshine", ALCOHOL}, 4},
	{{"Liver Killer", ALCOHOL}, 5},

	// HEAL effect
	{{"Diluted", HEAL}, 1},
	{{"Invigorating", HEAL}, 1},
	{{"Relieving", HEAL}, 2},
	{{"Healing", HEAL}, 3},
	{{"Remedy", HEAL}, 4},
	{{"All-Curing", HEAL}, 5},

	// DAMAGE effect
	{{"Tickling", DAMAGE}, 0},
	{{"Hurting", DAMAGE}, 1},
	{{"Sickening", DAMAGE}, 2},
	{{"Damaging", DAMAGE}, 3},
	{{"Harming", DAMAGE}, 4},
	{{"Annihilating", DAMAGE}, 5},

};
/// calculated by potion intensity
/// Current potion intensity formula is :
/// intensity += ingredient.intensity / 10
std::map<unsigned int, std::string> NameGen::potionType = {
	{0, "Flask"},
	{1, "Vial"},
	{2, "Bottle"},
	{3, "Jar"}
};
// Returns effect name based on intensity value using potionPotencyEffectName map
std::string NameGen::getEffectName(Effects effect, float intensity) {
	std::string name;
	intensity = floor(intensity);

	std::map<std::pair<std::string, Effects>, float>::iterator it;

	for (it = potionPotencyEffectName.begin(); it != potionPotencyEffectName.end(); it++) {
		if (it->second == floor(intensity) && it->first.second == effect) {
			name = it->first.first;
		}
	}

	return name;
}

/// Initialization of rnd engine so it can be used multiple times without recreation
NameGen::NameGen() {
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(0, 20);

	this->gen = gen;
	this->distr = distr;
}
int NameGen::random(int min, int max) {
	std::uniform_int_distribution<> dist(min, max);
	return dist(gen);
}
/// Potion name generator based on first letters of each ingredient name
/// potion: Potion to be given a name 
std::string NameGen::generateName(std::map<AlchemyObject*, unsigned int> usedIngredients) {
	std::string name;
	float intensity = 0;
	
	std::map<AlchemyObject*, unsigned int>::iterator it;

	if (usedIngredients.size() != 1) {
		for (it = usedIngredients.begin(); it != usedIngredients.end(); it++) {
			name += it->first->name[0];
			// Calculating intensity 
			intensity += it->first->intensity / 10;
		};
	} else {
		name = usedIngredients.begin()->first->name;
		intensity += usedIngredients.begin()->first->intensity / 10;
	}

	return name + " " + potionType[clamp((int)std::floor(intensity), 0, (int)potionType.size())];
}
/// Potion name generator based on dominating potion effect
/// potion: Potion to be given a name
std::string NameGen::generateNameE(std::map<AlchemyObject*, unsigned int> usedIngredients) {
	std::string name;
	float intensity = 0;

	std::map<AlchemyObject*, unsigned int>::iterator it;

	std::vector<Effects> effects;
	Effects dominatingEffect = ALCOHOL;

	for (it = usedIngredients.begin(); it != usedIngredients.end(); it++) {
		effects.push_back(it->first->effect);
		// Calculating intensity
		intensity += it->first->intensity / 10;
	}
	Effects lastEffect = ALCOHOL;
	for (Effects effect : effects) {
		dominatingEffect = effect;

		if (lastEffect > dominatingEffect)
			dominatingEffect = lastEffect;
		else
			lastEffect = dominatingEffect;
	}

	name = getEffectName(dominatingEffect, intensity);

	return name + " " + potionType[clamp((int)std::floor(intensity), 0, (int)potionType.size())];
}

/// Ingredient name generator
/// ingredient: Ingredient to be given a name
std::string NameGen::generateName() {
	return alchemicIngredientNames[distr(gen)] + " " + alchemicIngredientTypes[distr(gen)];
}