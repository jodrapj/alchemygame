#pragma once

#include <map>
#include <string>

enum Effects;
class AlchemyObject;

class Potion {
public:
	std::string name;
	std::map<Effects, unsigned int> effect;
	float intensity;
	Potion(std::map<AlchemyObject*, unsigned int> usedIngredients, std::string name);
};