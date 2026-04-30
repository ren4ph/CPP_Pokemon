#include <iostream>
#include <memory>
#include "battle/type_chart.h"
#include "utils/type_utils.h"
#include "core/inventory.h"
#include "core/pokemon.h"
#include "core/pokemon_factory.h"
#include "core/party.h"
#include "core/legendary_pokemon.h"
#include "battle/physical_move.h"
#include "battle/physical_multi_hit_move.h"
#include "battle/move.h"
#include "utils/rng.h"

int main() {
    RNG::get().seed(43);

    Party party = Party();
    party.loadParty();

    Pokemon* bulbasaur = party.getMember(0);
    bulbasaur->addMove(std::make_unique<PhysicalMultiHitMove>("Rock Toss", Type::ROCK, 40, -1, 35));
    bulbasaur->replaceMove(2, std::make_unique<PhysicalMove>("Blizzard", Type::ICE, 5, .70, 120, StatusEffect::FREEZE, .10));
    Pokemon* venusaur = party.getMember(2);
    venusaur->addMove(std::make_unique<PhysicalMove>("Tackle", Type::NORMAL, 35, -1, 40, .5f, .0f));

    std::cout << (bulbasaur->useMove(bulbasaur->getMoveByIndex(0).value(), *venusaur)).message;
    std::cout << (venusaur->useMove(venusaur->getMoveByIndex(0).value(), *bulbasaur)).message;
    party.printAll();
    

    return 0;
}
