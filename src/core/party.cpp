#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "party.h"
#include "pokemon.h"
#include "pokemon_factory.h"
#include "../utils/type_utils.h"
#include "../core/pokemon.h"
#include "../battle/move.h"

Party::Party() {
}

void Party::addPokemon(std::unique_ptr<Pokemon> p) {
    if (!isFull()) members.push_back(std::move(p));
    saveParty();
}

void Party::addPokemonInternal(std::unique_ptr<Pokemon> p) {
    if (!isFull()) members.push_back(std::move(p));
}

void Party::printAll() const {
    for (const auto& pokemon : members) {
        pokemon->printStats();
    }
}

int Party::getSize() const {
    return members.size();
}

bool Party::isFull() const {
    return getSize() >= MAX_SIZE;
}

std::optional<Pokemon*> Party::findByName(const std::string& name) const {
    for (const auto& p : members) {
        if (p->getName() == name) return p.get();
    }
    return std::nullopt;
}


Pokemon* Party::getMember(int index) const {
    if (index < 0 || index >= MAX_SIZE) return nullptr;
    return members[index].get();
}

void Party::loadParty() {
    auto partyFromFile = PokemonFactory().loadFromFile("src/save/game.sav");
    if (partyFromFile.empty()) return;
    for (auto &p : partyFromFile) {
        addPokemonInternal(std::move(p));
    }
    saveParty();
}

void Party::loadParty(std::string path) {
    auto partyFromFile = PokemonFactory().loadFromFile(path);
    if (partyFromFile.empty()) return;
    for (auto &p : partyFromFile) {
        addPokemonInternal(std::move(p));
    }
    saveParty();
}

void Party::saveParty() {
    if (members.empty()) return;
    std::ofstream save("src/save/game.sav");

    if (!save.is_open()) {
        std::cerr << "Could not open save file at: " << "save/game.sav";
        return;
    }

    int index = 0;
    for (const auto &p : members) {
        save << index++ << ',';
        save << p->getName() << ',';
        save << getStringFromType(p->getPrimaryType()) << ',';
        save << getStringFromType(p->getSecondaryType()) << ',';
        save << p->getHP() + p->getAttack() + p->getDefense() + p->getSpAtk() + p->getSpDef() + p->getSpeed() << ','; 
        save << p->getHP() << ',';
        save << p->getAttack() << ',';
        save << p->getDefense() << ',';
        save << p->getSpAtk() << ',';
        save << p->getSpDef() << ',';
        save << p->getSpeed() << ',';
        std::string isLegen = (p->isLegendary()) ? "True" : "False";
        save << isLegen;
        save << "\n";
    }

    return;
}