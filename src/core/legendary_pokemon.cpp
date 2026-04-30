#include "../battle/move.h"
#include "pokemon.h"
#include "legendary_pokemon.h"
#include <iostream>



bool LegendaryPokemon::isCatchable() const {
    return false;
}

void LegendaryPokemon::printStats() const {
    std::cout << "========================" << std::endl;
    std::cout << " *" << name << "*" << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "  HP:      " << hp << " / " << maxHP << std::endl;
    std::cout << "  Attack:  " << attack << std::endl;
    std::cout << "  Defense: " << defense << std::endl;
    std::cout << "  Sp.Atk:  " << spAtk << std::endl;
    std::cout << "  Sp.Def:  " << spDef << std::endl;
    std::cout << "  Speed:   " << speed << std::endl;
    std::cout << "========================" << std::endl;
    for (const auto& move : moves) {
        if (!move) continue;
        std::cout << "  " << move->getName() << ": PP:" << move->getPP() << " / " << move->getMaxPP() << "  Power: " << move->getPower() << "  Accuracy: " << move->getAccuracy() << std::endl;
    }
    std::cout << "\n\n";
}