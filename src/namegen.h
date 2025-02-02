#pragma once

#include <map>
#include <string>
#include <random>

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
	/// calculated by potion potency
	static std::map<unsigned int, std::string> potionType;
public:
	NameGen();
	int random(int min, int max);
	/// Potion name generator
	std::string generateName(std::map<AlchemyObject*, unsigned int> usedIngredients);
	/// Ingredient name generator
	std::string generateName();
};
