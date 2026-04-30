#include "multi_hit_move.h"
#include "../utils/rng.h"
#include "../core/pokemon.h"

MoveResult MultiHitMove::use(Pokemon& attacker, Pokemon& defender) {
    // single accuracy check for the first hit — if it misses, nothing happens
    if (!RNG::get().chance(accuracy) && !(accuracy == -1)) {
        return {true, 0, false, attacker.getName() + "'s " + name + " missed!\n"};
    }

    int totalDamage = 0;
    int hitCount = 0;
    int numHits = rollHitCount();

    decPP();

    for (int i = 0; i < numHits; i++) {
        if (i > 0 && !RNG::get().chance(accuracy) && !(accuracy == -1)) break; // subsequent hits can miss
        
        int dmg = calcDamage(attacker, defender);
        defender.takeDamage(dmg);
        totalDamage += dmg;
        hitCount++;

        if (defender.isFainted()) break;  // stop hitting a fainted pokemon
    }

    std::string msg = attacker.getName() + " used " + name + 
                      "! Hit " + std::to_string(hitCount) + " time(s) for " + std::to_string(totalDamage) + " total damage!\n";

    return {false, totalDamage, false, msg};
}

int MultiHitMove::rollHitCount() const {
    int roll = RNG::get().randInt(0, 7);
    if (roll <= 2) return 2;
    if (roll <= 5) return 3;
    if (roll == 6) return 4;
    return 5;
}