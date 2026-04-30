#pragma once 
#include "damaging_move.h"

class MultiHitMove : public DamagingMove {
    public:
        using DamagingMove::DamagingMove;  // inherit constructors
        MoveResult use(Pokemon& attacker, Pokemon& defender) override;

    protected:
        int rollHitCount() const;
        int minHits;
        int maxHits;
};