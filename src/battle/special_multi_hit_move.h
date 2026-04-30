#pragma once
#include "multi_hit_move.h"

class SpecialMultiHitMove : public MultiHitMove {
public:
    using MultiHitMove::MultiHitMove; 
    int calcDamage(const Pokemon& attacker, const Pokemon& defender) override;
};