#pragma once
#include <optional>
#include <string>
#include <vector>
#include "pokemon.h"

class MoveFactory {
    public:
        MoveFactory();    
    
        std::vector<std::unique_ptr<Move>> loadFromFile(const std::string& path);

    private:
        std::optional<std::unique_ptr<Move>> makeMoveFromLine(std::string line);
};