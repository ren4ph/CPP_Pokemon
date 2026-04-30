#pragma once
#include "damaging_move.h"

class SpecialMove : public DamagingMove {
    public:
        SpecialMove(std::string name, Type moveType, int PP, float accuracy, int power, StatusEffect effectType, float effectChance)
            :DamagingMove(name, moveType, PP, accuracy, power, effectType, effectChance, 0.0f, 0.0f) { };
        SpecialMove(std::string name, Type moveType, int PP, float accuracy, int power)
            :DamagingMove(name, moveType, PP, accuracy, power, 0.0f, 0.0f) { };
        SpecialMove(std::string name, Type moveType, int PP, float accuracy, int power, StatusEffect effectType, float effectChance, float recoilFraction, float drainFraction)
            :DamagingMove(name, moveType, PP, accuracy, power, effectType, effectChance, recoilFraction, drainFraction) { };
        SpecialMove(std::string name, Type moveType, int PP, float accuracy, int power, float recoilFraction, float drainFraction)
            :DamagingMove(name, moveType, PP, accuracy, power, recoilFraction, drainFraction) { };
        
        
        int calcDamage(const Pokemon& attacker, const Pokemon& defender) override;
};