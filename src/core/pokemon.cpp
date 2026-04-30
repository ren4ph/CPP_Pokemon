#include "pokemon.h"
#include <algorithm>
#include <iostream>
#include "../battle/move.h"
#include "../utils/effect_utils.h"

bool Pokemon::operator==(const Pokemon& other) const {
    return name == other.name;
}

bool Pokemon::operator<(const Pokemon& other) const {
    return name < other.name;
}

std::ostream& Pokemon::operator<<(std::ostream & os) {
    os << name;
    return os;
}

std::string Pokemon::getName() const {
    return name;
}

Type Pokemon::getPrimaryType() const {
    return primaryType;
}

Type Pokemon::getSecondaryType() const {
    return secondaryType;
}

bool Pokemon::isDualType() const {
    return dualType;
}

int Pokemon::getHP() const {
    return hp;
}

int Pokemon::getMaxHP() const {
    return maxHP;
}

int Pokemon::getAttack() const {
    return attack;
}

int Pokemon::getEffectiveAttack() const {
    return majorEffect == StatusEffect::BURN ? attack / 2 : attack;
}

int Pokemon::getDefense() const {
    return defense;
}

int Pokemon::getSpAtk() const {
    return spAtk;
}

int Pokemon::getSpDef() const {
    return spDef;
}

int Pokemon::getSpeed() const {
    return speed;
}

int Pokemon::getEffectiveSpeed() const {
    return majorEffect == StatusEffect::PARALYSIS ? speed / 4 : speed;
}

float Pokemon::getCriticalChance() const {
    return criticalChance;
}


std::optional<Move*> Pokemon::getMoveByName(std::string name) const {
    for (const auto& m : moves) {
        if (m && m->getName() == name) return m.get();
    }
    return std::nullopt;
}

std::optional<Move*> Pokemon::getMoveByIndex(int i) const {
    try {
        return moves.at(i).get();
    } catch (const std::out_of_range& e) {
        std::cerr << "Index out of move bounds (0-3), is instead " << i << "\n|\nv\n" << e.what() << std::endl;
    }
    return std::nullopt;
}

std::optional<int> Pokemon::getIndexByMove(Move* m) const {
    return getIndexByName(m->getName());
}

std::optional<int> Pokemon::getIndexByName(std::string name) const {
    int i = 0;
    for (const auto& move : moves) {
        if (move->getName() == name) return i;
        i++;
    }
    return std::nullopt;
}

bool Pokemon::canMove() const {
    bool cm = true;
    cm &= majorEffect != StatusEffect::SLEEP;
    cm &= majorEffect != StatusEffect::FREEZE;
    return cm;
}

bool Pokemon::hasMaxMoves() const {
    return false; 
}

void Pokemon::addMove(std::unique_ptr<Move> m) {
    for (int i = 0; i < 4; i++) {
        if (!moves[i]) {
            moves[i] = std::move(m);
            return;
        }
    }
    std::cerr << "Pokemon already has 4 moves\n";
}

void Pokemon::replaceMove(int i, std::unique_ptr<Move> m) {
    if (i < 0 || i >= 4) std::cerr << "Index for replaceMove out of range (0-3): " << i << "\n";
    moves[i] = std::move(m);
    return;
}

void Pokemon::replaceMove(std::string name, std::unique_ptr<Move> m) {
    std::optional<int> i = getIndexByName(name);
    if (i.has_value()) replaceMove(i.value(), std::move(m));
    return;
}

void Pokemon::replaceMove(Move* toReplace, std::unique_ptr<Move> m) {
    std::optional<int> i = getIndexByMove(toReplace);
    if (i.has_value()) replaceMove(i.value(), std::move(m));
    return;
}

MoveResult Pokemon::useMove(Move* move, Pokemon& p) {
    return move->use(*this, p);
}

void Pokemon::takeDamage(int amount) {
    hp = std::max(hp - amount, 0);
}

void Pokemon::applyEffect(StatusEffect s) {
    majorEffect = s;
}

void Pokemon::applyEndOfTurnEffects() {
    switch (majorEffect){
        case (StatusEffect::BURN):
            takeDamage(maxHP / 8);
            return;
        case (StatusEffect::SLEEP):
            sleepCounter--;
            if (sleepCounter <= 0) {
                sleepCounter = 0;
                majorEffect = StatusEffect::NONE;
            }
            return;
        case (StatusEffect::POISON):
            takeDamage(maxHP / 8);
            return;
        case (StatusEffect::TOXIC):
            takeDamage((maxHP / 16) * toxicCounter++);
            return;
        default:
            return;
    }
}

void Pokemon::heal(int amount) {
    hp = std::min(hp + amount, maxHP);
}

bool Pokemon::isFainted() const {
    return hp <= 0;
}

void Pokemon::printStats() const {
    std::cout << "========================" << std::endl;
    std::cout << "  " << name << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "  HP:      " << hp << " / " << maxHP << std::endl;
    std::cout << "  Attack:  " << attack << std::endl;
    std::cout << "  Defense: " << defense << std::endl;
    std::cout << "  Sp.Atk:  " << spAtk << std::endl;
    std::cout << "  Sp.Def:  " << spDef << std::endl;
    std::cout << "  Speed:   " << speed << std::endl;
    std::cout << "========================" << std::endl;
    for (const auto& move : moves) {
        if (!move) continue;
        std::cout << "  " << move->getName() << ": PP:" << move->getPP() << " / " << move->getMaxPP() << "  Power: " << move->getPower() << "  Accuracy: " << move->getAccuracy() << std::endl;
    }
    std::cout << "========================" << std::endl;
    if (majorEffect != StatusEffect::NONE) std::cout << "  " << majorEffect << std::endl;
    std::cout << "\n\n";
}
