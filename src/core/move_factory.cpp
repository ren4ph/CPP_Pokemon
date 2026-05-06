#include "move_factory.h"
#include "../battle/fixed_damage_move.h"
#include "../battle/move.h"
#include "../battle/physical_move.h"
#include "../battle/physical_multi_hit_move.h"
#include "../battle/special_move.h"
#include "../battle/special_multi_hit_move.h"
#include "../battle/struggle_move.h"
#include "../utils/effect_utils.h"
#include "../utils/move_utils.h"
#include "../utils/stat_utils.h"
#include "../utils/type_utils.h"
#include "legendary_pokemon.h"
#include "pokemon.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

MoveFactory::MoveFactory() { return; }

std::vector<std::unique_ptr<Move>>
MoveFactory::loadFromFile(const std::string &path) {
	std::vector<std::unique_ptr<Move>> list;

	std::ifstream file(path);

	if (!file.is_open()) {
		std::cerr << "Failed to open file: " << path << "\n";
		return list;
	}

	std::string line;
	std::string token;

	while (std::getline(file, line)) {
		auto move = makeMoveFromLine(line);
		if (move) {
			list.push_back(std::move(*move));
		} else {
			std::cerr << "Failed to create move from line: " << line << "\n";
		}
	}

	return list;
}

std::optional<std::unique_ptr<Move>>
MoveFactory::makeMoveFromLine(std::string line) {
	std::string token;
	std::stringstream ss(line);

	int index;
	std::string name;
	Type moveType;
	int PP;
	float accuracy;
	int power;
	bool hasEffect;
	StatusEffect effectType;
	float effectChance;
	bool hasRecoil;
	float recoilFraction, drainFraction;
	MoveKind moveKind;
	int multiHits;
	bool hasStatEffect;
	StatType statType;
	bool onSelf;
	int stageEffect;

	try {
		std::getline(ss, token, ',');
		int index = std::stoi(token); // Unused
		std::getline(ss, token, ',');
		name = token;
		std::getline(ss, token, ',');
		moveType = getTypeFromString(token);
		std::getline(ss, token, ',');
		PP = std::stoi(token); // Unused for now
		std::getline(ss, token, ',');
		accuracy = std::stoi(token);
		std::getline(ss, token, ',');
		power = std::stoi(token);
		std::getline(ss, token, ',');
		hasEffect = token == "True";
		std::getline(ss, token, ',');
		effectType = getEffectFromString(token);
		std::getline(ss, token, ',');
		effectChance = std::stof(token);
		std::getline(ss, token, ',');
		hasRecoil = token == "True";
		std::getline(ss, token, ',');
		recoilFraction = std::stof(token);
		std::getline(ss, token, ',');
		drainFraction = std::stof(token);
		std::getline(ss, token, ',');
		moveKind = getMoveKindFromString(token);
		std::getline(ss, token, ',');
		multiHits = std::stoi(token);
		std::getline(ss, token, ',');
		hasStatEffect = token == "True";
		std::getline(ss, token, ',');
		statType = getStatTypeFromString(token);
		std::getline(ss, token, ',');
		onSelf = token == "True";
		std::getline(ss, token, ',');
		stageEffect = std::stoi(token);

	} catch (const std::invalid_argument &e) {
		std::cerr << "Bad data in CSV: " << token << "\n";
		return std::nullopt;
	}

	std::unique_ptr<Move> p;

	if (moveKind == MoveKind::PHYSICAL) {
		p = std::make_unique<PhysicalMove>(name, moveType, PP, accuracy, power,
										   effectType, effectChance,
										   recoilFraction, drainFraction);
	} else if (moveKind == MoveKind::SPECIAL) {
		p = std::make_unique<SpecialMove>(name, moveType, PP, accuracy, power,
										  effectType, effectChance,
										  recoilFraction, drainFraction);
	} /* else if (moveKind == MoveKind::STATUS) {
		p = std::make_unique<StatusMove>(		name, moveType, PP, accuracy,
	power, effectType, effectChance, recoilFraction, drainFraction);
	}*/
	else if (moveKind == MoveKind::FIXED) {
		p = std::make_unique<FixedDamageMove>(name, moveType, PP, accuracy,
											  power, effectType, effectChance,
											  recoilFraction, drainFraction);
	} else if (moveKind == MoveKind::STRUGGLE) {
		p = std::make_unique<StruggleMove>();
	} else if (moveKind == MoveKind::PHYSICAL_MULTI_HIT) {
		p = std::make_unique<PhysicalMultiHitMove>(
			name, moveType, PP, accuracy, power, effectType, effectChance,
			recoilFraction, drainFraction);
	} else if (moveKind == MoveKind::SPECIAL_MULTI_HIT) {
		p = std::make_unique<SpecialMultiHitMove>(
			name, moveType, PP, accuracy, power, effectType, effectChance,
			recoilFraction, drainFraction);
	} else {
		return std::nullopt;
	}

	return p;
}
