#include "AlchemyObject.h"

AlchemyObject::AlchemyObject(Effects effect, IngrType type, float intensity, bool canBeTurnedInPowder, std::string name)
	: effect(effect), type(type), intensity(intensity), name(name) {}
