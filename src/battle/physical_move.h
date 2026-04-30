#pragma once
#include "damaging_move.h"
#include "../core/pokemon.h"

class PhysicalMove : public DamagingMove {
    public:
        PhysicalMove(std::string name, Type moveType, int PP, float accuracy, int power, StatusEffect effectType, float effectChance)
            :DamagingMove(name, moveType, PP, accuracy, power, effectType, effectChance) { };
        PhysicalMove(std::string name, Type moveType, int PP, float accuracy, int power)
            :DamagingMove(name, moveType, PP, accuracy, power) { };

        int calcDamage(const Pokemon& attacker, const Pokemon& defender) override;
};