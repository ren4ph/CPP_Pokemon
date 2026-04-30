#pragma once
#include <unordered_map>
#include "../core/pokemon.h"
#include "../utils/type_utils.h"

class TypeChart {
    public:
        TypeChart();
        float getEffectiveness(Type attacking, Type defending) const;
        float getEffectivenessAgainst(Type atk, const Pokemon& defender) const;

    private:
        std::unordered_map<Type,
            std::unordered_map<Type, float, EnumClassHash>,
        EnumClassHash> chart;

        void set(Type atk, Type def, float multiplier);
};