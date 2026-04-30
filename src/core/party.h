#pragma once
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include "pokemon.h"

class Party {
    public: 
        Party();
        void addPokemon(std::unique_ptr<Pokemon> p);
        void printAll() const;
        int getSize() const;
        bool isFull() const;
        Pokemon* getMember(int index) const;

        std::optional<Pokemon*> findByName(const std::string& name) const;
        void loadParty();
        void loadParty(std::string path);
        void saveParty();

    private:
        void addPokemonInternal(std::unique_ptr<Pokemon> p);

        std::vector<std::unique_ptr<Pokemon>> members;
        static const int MAX_SIZE = 6;
    };