#include "physical_move.h"
#include "type_chart.h"
#include "../utils/rng.h"

int PhysicalMove::calcDamage(const Pokemon& attacker, const Pokemon& defender) {
    float STAB = (moveType == attacker.getPrimaryType() || moveType == attacker.getSecondaryType()) ? 1.5 : 1.0;
    float TypeEffectiveness = TypeChart().getEffectivenessAgainst(moveType, defender);
    float CriticalHit = RNG::get().chance(attacker.getCriticalChance()) ? 2.0 : 1.0;
    float Random = RNG::get().randInt(217, 255) / 255.;

    float Modifier = STAB * TypeEffectiveness * CriticalHit * Random;

    int Level = 100;
    int Power = power;
    int Atk = attacker.getEffectiveAttack();
    int Def = defender.getDefense();

    int Damage = ((((2 * Level / 5 + 2) * Power * Atk / Def) / 50) + 2) * Modifier;

    return Damage;
}
