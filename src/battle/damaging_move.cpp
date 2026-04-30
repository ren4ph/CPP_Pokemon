#include <string>
#include <iostream>
#include "damaging_move.h"
#include "../core/pokemon.h"
#include "../utils/rng.h"
#include "move.h"

int DamagingMove::getPower() const {
    return power;
}

bool DamagingMove::isEffectMove() const {
    return hasEffect;
}

StatusEffect DamagingMove::getEffectType() const {
    return effectType;
}

float DamagingMove::getEffectChance() const {
    return effectChance;
}

MoveResult DamagingMove::use(Pokemon& attacker, Pokemon& defender) {
    MoveResult result = {false, 0, false, "Out of pp.\n"};

    std::cout << name << " " << PP << " / " << maxPP << " \n";

    if (!canUse()) return result;

    result.message = "But it failed!\n";
    
    decPP();

    if (!RNG::get().chance(accuracy) && accuracy != -1) return result;

    int damage = calcDamage(attacker, defender);
    defender.takeDamage(damage);
    result.missed = true;
    result.damageDealt = damage;
    result.message = name + " hits for " + std::to_string(damage) + " damage!\n";

    if (!hasEffect) return result;
    
    if (!RNG::get().chance(effectChance)) return result;

    defender.applyEffect(effectType);

    result.statusApplied = true;
    result.message = result.message + "It applies effect " + " (placeholder implement statuseffect string conversion)!\n";

    return result;
}