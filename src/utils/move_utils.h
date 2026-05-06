#pragma once

#include <string>
#include <unordered_map>
enum class MoveKind {
	PHYSICAL,
	SPECIAL,
	PHYSICAL_MULTI_HIT,
	SPECIAL_MULTI_HIT,
	STRUGGLE,
	STATUS,
	FIXED
};

std::string getStringFromMoveKind(MoveKind k);
MoveKind getMoveKindFromString(std::string s);

inline std::unordered_map<MoveKind, std::string> moveKindToString = {
	{MoveKind::PHYSICAL, "Physical"},
	{MoveKind::SPECIAL, "Special"},
	{MoveKind::PHYSICAL_MULTI_HIT, "PhysicalMultiHit"},
	{MoveKind::SPECIAL_MULTI_HIT, "SpecialMultiHit"},
	{MoveKind::STRUGGLE, "Struggle"},
	{MoveKind::STATUS, "Status"},
	{MoveKind::FIXED, "Fixed"},
};

inline std::unordered_map<std::string, MoveKind> stringToMoveKind = {
	{"Physical", MoveKind::PHYSICAL},
	{"Special", MoveKind::SPECIAL},
	{"PhysicalMultiHit", MoveKind::PHYSICAL_MULTI_HIT},
	{"SpecialMultiHit", MoveKind::SPECIAL_MULTI_HIT},
	{"Struggle", MoveKind::STRUGGLE},
	{"Status", MoveKind::STATUS},
	{"Fixed", MoveKind::FIXED},
};

std::ostream &operator<<(std::ostream &os, MoveKind k);
