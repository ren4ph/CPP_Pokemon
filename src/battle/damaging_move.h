#pragma once
#include "move.h"
#include "../core/types.h"

class Pokemon;

class DamagingMove : public Move {
    public:
        DamagingMove(std::string name, Type moveType, int PP, float accuracy, int power, StatusEffect effectType, float effectChance)
            :Move(name, moveType, PP, accuracy), power(power), hasEffect(true), effectType(effectType), effectChance(effectChance) { };
        DamagingMove(std::string name, Type moveType, int PP, float accuracy, int power)
            :Move(name, moveType, PP, accuracy), power(power), hasEffect(false), effectType(StatusEffect::NONE), effectChance(0.0) { };

        virtual ~DamagingMove() = default;

        MoveResult use(Pokemon& attacker, Pokemon& defender);
        virtual int calcDamage(const Pokemon& attacker, const Pokemon& defender) = 0;

        int getPower() const;
        bool isEffectMove() const;
        StatusEffect getEffectType() const;
        float getEffectChance() const;

    protected:
        int power;
        bool hasEffect;
        StatusEffect effectType;
        float effectChance;

};