#pragma once

#include <string>
#include "enums.h"

// Alchemic intensity table
// 0: Very weak: Effect is so weak it can't be felt
// 1: Weak: Effect is weak enough to be useless 
// 2: Neutral: Normal effect
// 3: Intense: Effect is multiplied by 1.5 
// 4: Very intense: Effect is doubled
// 5: Powerful: Effect is tripled
// >5: Stunning: Effect is quadripled but some bodies can't stand it
// >100: Fatal: Effect is so strong it causes liver failure

class AlchemyObject {
public:
	Effects effect;
	IngrType type;
	float intensity;
	std::string name;
	AlchemyObject(Effects effect, IngrType type, float intensity, bool canBeTurnedInPowder, std::string name);
};