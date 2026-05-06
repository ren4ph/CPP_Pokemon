#pragma once
#include "damaging_move.h"

class StruggleMove : public DamagingMove {
  public:
	StruggleMove() : DamagingMove("Struggle", Type::NORMAL, 254, -1, 50) {};

	MoveResult use(Pokemon &attacker, Pokemon &defender) override;
	int calcDamage(const Pokemon &attacker, const Pokemon &defender) override;
};
