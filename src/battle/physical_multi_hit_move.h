#pragma once
#include "multi_hit_move.h"

class PhysicalMultiHitMove : public MultiHitMove {
public:
    using MultiHitMove::MultiHitMove;  // inherit constructors
    int calcDamage(const Pokemon& attacker, const Pokemon& defender) override;
};