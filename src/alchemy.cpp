#include "alchemy.h"

#include "AlchemyObject.h"
#include "Potion.h"
#include "namegen.h"
#include "enums.h"

// Current held potions with quantity as value
std::map<Potion*, unsigned int> Alchemy::potions;
// Current ingredient list with quantity as value
std::map<AlchemyObject*, unsigned int> Alchemy::ingredients;
// Potion ingredient generation buffer
std::map<AlchemyObject*, unsigned int> Alchemy::usedIngredients;
// Generated potion list so it can be recrafted
std::map<Potion, std::pair<AlchemyObject, unsigned int>> exitstingPotions;

// Add ingredient to "cauldron"
void Alchemy::addIngredient(AlchemyObject* ingredient) {
	ingredients[ingredient] -= 1;
	usedIngredients[ingredient] += 1;
}

// Potion generation
void Alchemy::mix(NameGen* gen) {
	Potion* potion = new Potion(usedIngredients, gen->generateName(usedIngredients));
	potions[potion] += 1;
}

// Destroy all ingredients used in potion generation
void Alchemy::emptyCauldron() {
	usedIngredients.clear();
}
