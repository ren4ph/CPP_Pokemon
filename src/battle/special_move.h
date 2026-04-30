#pragma once
#include "damaging_move.h"

class SpecialMove : public DamagingMove {
    public:
        SpecialMove(std::string name, Type moveType, int PP, float accuracy, int power, StatusEffect effectType, float effectChance)
            :DamagingMove(name, moveType, PP, accuracy, power, effectType, effectChance) { };
        SpecialMove(std::string name, Type moveType, int PP, float accuracy, int power)
            :DamagingMove(name, moveType, PP, accuracy, power) { };

        int calcDamage(const Pokemon& attacker, const Pokemon& defender) override;
};