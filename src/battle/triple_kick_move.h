#pragma once
#include "multi_hit_move.h"

class TripleKickMove : public MultiHitMove {
    public:
        MoveResult use(Pokemon& attacker, Pokemon& defender) override;

    protected:
        int rollHitCount() const { return 3; }
        static const int BASE_POWERS[3];
};