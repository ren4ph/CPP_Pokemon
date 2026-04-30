#pragma once
#include "damaging_move.h"
#include "../core/pokemon.h"

class PhysicalMove : public DamagingMove {
    public:
        PhysicalMove(std::string name, Type moveType, int PP, float accuracy, int power, StatusEffect effectType, float effectChance)
            :DamagingMove(name, moveType, PP, accuracy, power, effectType, effectChance, 0.0f, 0.0f) { };
        PhysicalMove(std::string name, Type moveType, int PP, float accuracy, int power)
            :DamagingMove(name, moveType, PP, accuracy, power, 0.0f, 0.0f) { };
        PhysicalMove(std::string name, Type moveType, int PP, float accuracy, int power, StatusEffect effectType, float effectChance, float recoilFraction, float drainFraction)
            :DamagingMove(name, moveType, PP, accuracy, power, effectType, effectChance, recoilFraction, drainFraction) { };
        PhysicalMove(std::string name, Type moveType, int PP, float accuracy, int power, float recoilFraction, float drainFraction)
            :DamagingMove(name, moveType, PP, accuracy, power, recoilFraction, drainFraction) { };

        int calcDamage(const Pokemon& attacker, const Pokemon& defender) override;
};