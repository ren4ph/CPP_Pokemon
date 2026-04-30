#include <fstream>
#include <iostream>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <vector>
#include "legendary_pokemon.h"
#include "pokemon.h"
#include "../battle/move.h"
#include "move_factory.h"
#include "../utils/type_utils.h"

MoveFactory::MoveFactory() {
    return;
}

std::vector<std::unique_ptr<Move>> MoveFactory::loadFromFile(const std::string& path) {
    std::vector<std::unique_ptr<Move>> list;

    std::ifstream file(path);

    if (!file.is_open()) { std::cerr << "Failed to open file: " << path << "\n"; return list; }

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

std::optional<std::unique_ptr<Move>> MoveFactory::makeMoveFromLine(std::string line) {
    std::string token;
    std::stringstream ss(line);
    
    std::string name = "";
    Type primaryType;
    Type secondaryType;
    int totalStats;
    int hp;
    int attack;
    int defense;
    int spAtk;
    int spDef;
    int speed;
    bool isLegendary;

    try {
        std::getline(ss, token, ',');
        int index = std::stoi(token); // Unused
        std::getline(ss, token, ',');
        name = token;
        std::getline(ss, token, ',');
        primaryType = getTypeFromString(token);
        std::getline(ss, token, ',');
        secondaryType = getTypeFromString(token);
        std::getline(ss, token, ',');
        totalStats = std::stoi(token); // Unused for now
        std::getline(ss, token, ',');
        hp = std::stoi(token);
        std::getline(ss, token, ',');
        attack = std::stoi(token);
        std::getline(ss, token, ',');
        defense = std::stoi(token);
        std::getline(ss, token, ',');
        spAtk = std::stoi(token);
        std::getline(ss, token, ',');
        spDef = std::stoi(token);
        std::getline(ss, token, ',');
        speed = std::stoi(token);
        std::getline(ss, token, ',');
        isLegendary = token == "True";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Bad data in CSV: " << token << "\n";
        return std::nullopt;
    }
    if (isLegendary) {
        return std::make_unique<LegendaryMove>(name, primaryType, secondaryType, hp, attack, defense, spAtk, spDef, speed);
    }

    return std::make_unique<Move>(name, primaryType, secondaryType, hp, attack, defense, spAtk, spDef, speed);

}