#pragma once

#include <map>
#include <string>
#include <random>

#include "enums.h"

class AlchemyObject;
class Potion;

//std::random_device rd;
//std::mt19937 gen(rd());
//std::uniform_int_distribution<> distr(0, 20);

class NameGen {
	std::random_device rd;
	std::mt19937 gen;
	std::uniform_int_distribution<> distr;

	static std::map<unsigned int, std::string> alchemicIngredientNames;
	static std::map<unsigned int, std::string> alchemicIngredientTypes;
	static std::map<unsigned int, std::string> potionName;
	static std::map<std::pair<std::string, Effects>, float> potionPotencyEffectName;
	/// calculated by potion potency
	static std::map<unsigned int, std::string> potionType;

	std::string getEffectName(Effects effect, float intensity);
public:
	NameGen();
	/// Returns random value in given range
	int random(int min, int max);
	/// Potion name generator based on first letters of each ingredient
	std::string generateName(std::map<AlchemyObject*, unsigned int> usedIngredients);
	/// Potion name generator based on dominating potion effect
	std::string generateNameE(std::map<AlchemyObject*, unsigned int> usedIngredients);
	/// Ingredient name generator
	std::string generateName();
};
