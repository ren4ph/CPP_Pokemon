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
#include "pokemon_factory.h"
#include "../utils/type_utils.h"

PokemonFactory::PokemonFactory() {
    return;
}

std::vector<std::unique_ptr<Pokemon>> PokemonFactory::loadFromFile(const std::string& path) {
    std::vector<std::unique_ptr<Pokemon>> list;

    std::ifstream file(path);

    if (!file.is_open()) { std::cerr << "Failed to open file: " << path << "\n"; return list; }

    std::string line;
    std::string token;

    while (std::getline(file, line)) {
       auto pokemon = makePokemonFromLine(line);
       if (pokemon) {
            list.push_back(std::move(*pokemon));
       } else {
            std::cerr << "Failed to create pokemon from line: " << line << "\n"; 
       }
    }

    return list;
}

std::optional<std::unique_ptr<Pokemon>> PokemonFactory::makePokemonFromLine(std::string line) {
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
        return std::make_unique<LegendaryPokemon>(name, primaryType, secondaryType, hp, attack, defense, spAtk, spDef, speed);
    }

    return std::make_unique<Pokemon>(name, primaryType, secondaryType, hp, attack, defense, spAtk, spDef, speed);

}