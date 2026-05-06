#pragma once

#include <string>
#include <unordered_map>
enum class StatType { HP, ATK, DEF, SPATK, SPDEF, SPD };

StatType getStatTypeFromString(std::string s);
std::string getStringFromStatType(StatType st);

inline std::unordered_map<StatType, std::string> stringFromStatType = {
	{StatType::HP, "HP"},		{StatType::ATK, "ATK"},
	{StatType::DEF, "DEF"},		{StatType::SPATK, "SPATK"},
	{StatType::SPDEF, "SPDEF"}, {StatType::SPD, "SPD"},
};

inline std::unordered_map<std::string, StatType> statTypeFromString = {
	{"HP", StatType::HP},		{"ATK", StatType::ATK},
	{"DEF", StatType::DEF},		{"SPATK", StatType::SPATK},
	{"SPDEF", StatType::SPDEF}, {"SPD", StatType::SPD},
};

std::ostream &operator<<(std::ostream &os, StatType statType);
