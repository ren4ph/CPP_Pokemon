#pragma once
#include <string>
#include "pokemon.h"

class Move;

class LegendaryPokemon : public Pokemon {
    public:
        LegendaryPokemon(std::string name, Type primaryType, Type secondaryType, int hp,  int attack, int defense, int spAtk, int spDef, int speed)
        : Pokemon(name, primaryType, secondaryType, hp, attack, defense, spAtk, spDef, speed) { }

        LegendaryPokemon(std::string name, Type primaryType, int hp,  int attack, int defense, int spAtk, int spDef, int speed)
        : Pokemon(name, primaryType, hp, attack, defense, spAtk, spDef, speed) { }

        LegendaryPokemon(std::string name)
        : Pokemon(name, Type::NORMAL, Type::NORMAL, 8, 8, 4, 1, 3, 0) { } 

        virtual ~LegendaryPokemon() = default;

        bool isCatchable() const override;
        bool isLegendary() const override { return true; };
        void printStats() const override;

    private:
        static const int LEGENDARY_CATCH_RATE = 3;
};