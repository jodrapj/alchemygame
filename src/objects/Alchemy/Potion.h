#pragma once

#include <map>
#include <string>
#include "enums.h"

class AlchemyObject;

class Potion {
public:
	std::string name;
	std::map<Effects, unsigned int> effect;
	float intensity;
	Potion(std::map<AlchemyObject*, unsigned int> usedIngredients, std::string name);

	friend bool operator==(Potion const& p1, Potion const& p2);
};