#include "struggle_move.h"
#include "../utils/rng.h"
#include "../core/pokemon.h"

MoveResult StruggleMove::use(Pokemon& attacker, Pokemon& defender) {
    MoveResult result = {false, 0, true, "Out of pp.\n"};

    int damage = calcDamage(attacker, defender);
    defender.takeDamage(damage);
    result.missed = true;
    result.damageDealt = damage;
    result.message = name + " struggles and hits for " + std::to_string(damage) + " damage!\n";

    attacker.takeDamage(attacker.getMaxHP() / 4);
    result.message += "Struggling hurts itself for " + std::to_string(attacker.getMaxHP() / 4) + " damage.\n";

    return result;
}

int StruggleMove::calcDamage(const Pokemon& attacker, const Pokemon& defender) {
    float CriticalHit = RNG::get().chance(attacker.getCriticalChance()) ? 2.0 : 1.0;
    float Random = RNG::get().randInt(217, 255) / 255.;

    float Modifier = CriticalHit * Random;

    int Level = 100;
    int Power = power;
    int Atk = attacker.getEffectiveAttack();
    int Def = defender.getDefense();

    int Damage = ((((2 * Level / 5 + 2) * Power * Atk / Def) / 50) + 2) * Modifier;

    return Damage;
}