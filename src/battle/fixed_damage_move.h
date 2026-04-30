#pragma once
#include "damaging_move.h"


class FixedDamageMove : public DamagingMove {
    int calcDamage(const Pokemon& attacker, const Pokemon& defender);
};