#include "Potion.h"
#include "AlchemyObject.h"

Potion::Potion(std::map<AlchemyObject*, unsigned int> usedIngredients, std::string name) : name(name), intensity(0) {
	std::map<AlchemyObject*, unsigned int>::iterator it;

	for (it = usedIngredients.begin(); it != usedIngredients.end(); it++) {
		effect[it->first->effect] = it->first->intensity * it->second;
		intensity += it->first->intensity / 10;
	}
}