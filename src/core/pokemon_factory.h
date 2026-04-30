#pragma once
#include <optional>
#include <string>
#include <vector>
#include "pokemon.h"

class PokemonFactory {
    public:
        PokemonFactory();    
    
        std::vector<std::unique_ptr<Pokemon>> loadFromFile(const std::string& path);

    private:
        std::optional<std::unique_ptr<Pokemon>> makePokemonFromLine(std::string line);
};