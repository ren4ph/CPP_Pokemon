#pragma once
#include "../core/pokemon.h"
#include <ostream>
#include <string>
#include <unordered_map>

std::string getStringFromEffect(Type t);
StatusEffect getEffectFromString(std::string s);

inline std::unordered_map<std::string, StatusEffect> stringToEffect = {
	{"None", StatusEffect::NONE},	  {"Burn", StatusEffect::BURN},
	{"Freeze", StatusEffect::FREEZE}, {"Paralysis", StatusEffect::PARALYSIS},
	{"Poison", StatusEffect::POISON}, {"Sleep", StatusEffect::SLEEP},
	{"Toxic", StatusEffect::TOXIC},
};

inline std::unordered_map<StatusEffect, std::string> effectToString = {
	{StatusEffect::NONE, "None"},	  {StatusEffect::BURN, "Burn"},
	{StatusEffect::FREEZE, "Freeze"}, {StatusEffect::PARALYSIS, "Paralysis"},
	{StatusEffect::POISON, "Poison"}, {StatusEffect::SLEEP, "Sleep"},
	{StatusEffect::TOXIC, "Toxic"},
};

std::ostream &operator<<(std::ostream &os, StatusEffect t);
