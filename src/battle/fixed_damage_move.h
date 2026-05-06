#pragma once
#include "damaging_move.h"

class FixedDamageMove : public DamagingMove {
	using DamagingMove::DamagingMove;
	int calcDamage(const Pokemon &attacker, const Pokemon &defender);
};
