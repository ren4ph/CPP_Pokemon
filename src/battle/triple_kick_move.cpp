#include "triple_kick_move.h"
#include "../utils/rng.h"
#include "../core/pokemon.h"

const int TripleKickMove::BASE_POWERS[3] = {10, 20, 30};

MoveResult TripleKickMove::use(Pokemon& attacker, Pokemon& defender) {
    int totalDamage = 0;
    int hitCount = 0;

    for (int i = 0; i < 3; i++) {
        // each hit has independent accuracy check
        if (!RNG::get().chance(accuracy / 100.0f)) break;

        // temporarily set power for this hit
        power = BASE_POWERS[i];
        int dmg = calcDamage(attacker, defender);
        defender.takeDamage(dmg);
        totalDamage += dmg;
        hitCount++;

        if (defender.isFainted()) break;
    }

    if (hitCount == 0)
        return {true, 0, false, attacker.getName() + "'s Triple Kick missed!"};

    return {false, totalDamage, false, 
            attacker.getName() + "'s Triple Kick hit " + std::to_string(hitCount) + " time(s)!"};
}