#include <iostream>
#include <string>
#include "move.h"
#include "../core/pokemon.h"

MoveResult Move::use(Pokemon& attacker, Pokemon& defender) { return {false, 0, false, "virtual"}; }

std::string Move::getName() const {
    return name;
}

Type Move::getMoveType() const {
    return moveType;
}

int Move::getPP() const {
    return PP;
}

int Move::getMaxPP() const {
    return maxPP;
}

float Move::getAccuracy() const {
    return accuracy;
}

bool Move::checkPP() const {
    return PP > 0;
}

bool Move::canUse() const {
    return checkPP() && accuracy != 0;
}

void Move::setPP(int newPP) {
    PP = newPP;
}

void Move::incPP(int diff) {
    PP += diff;
}

void Move::incPP() {
    PP++;
}

void Move::decPP(int diff) {
    PP -= diff;
}

void Move::decPP() {
    PP--;
}

void Move::resetPP() {
    PP = maxPP;
}

void Move::setMaxPP(int newMaxPP) {
    maxPP = newMaxPP;
}

void Move::incMaxPP(int diff) {
    maxPP += diff;
}

void Move::incMaxPP() {
    maxPP++;
}

void Move::decMaxPP(int diff) {
    maxPP -= diff;
}

void Move::decMaxPP() {
    maxPP--;
}
