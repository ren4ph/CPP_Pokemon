#pragma once
#include "../core/pokemon.h"
#include <string>
#include <ostream>
#include <unordered_map>

std::string getStringFromType(Type t);
Type getTypeFromString(std::string s);
std::string getTypePair(const Pokemon& p);

struct EnumClassHash {
    template <typename T>
    std::size_t operator()(T t) const {
        return  static_cast<std::size_t>(static_cast<int>(t));
    }
};

inline std::unordered_map<std::string, Type> stringToType = {
    {"Bug", Type::BUG},
    {"Dark", Type::DARK},
    {"Dragon", Type::DRAGON},
    {"Electric", Type::ELECTRIC},
    {"Fairy", Type::FAIRY},
    {"Fighting", Type::FIGHTING},
    {"Fire", Type::FIRE},
    {"Flying", Type::FLYING},
    {"Ghost", Type::GHOST},
    {"Grass", Type::GRASS},
    {"Ground", Type::GROUND},
    {"Ice", Type::ICE},
    {"Normal", Type::NORMAL},
    {"Poison", Type::POISON},
    {"Psychic", Type::PSYCHIC},
    {"Rock", Type::ROCK},
    {"Steel", Type::STEEL},
    {"Water", Type::WATER},
};

inline std::unordered_map<Type, std::string> typeToString = {
    {Type::BUG, "Bug"},
    {Type::DARK, "Dark"},
    {Type::DRAGON, "Dragon"},
    {Type::ELECTRIC, "Electric"},
    {Type::FAIRY, "Fairy"},
    {Type::FIGHTING, "Fighting"},
    {Type::FIRE, "Fire"},
    {Type::FLYING, "Flying"},
    {Type::GHOST, "Ghost"},
    {Type::GRASS, "Grass"},
    {Type::GROUND, "Ground"},
    {Type::ICE, "Ice"},
    {Type::NORMAL, "Normal"},
    {Type::POISON, "Poison"},
    {Type::PSYCHIC, "Psychic"},
    {Type::ROCK, "Rock"},
    {Type::STEEL, "Steel"},
    {Type::WATER, "Water"},
};

std::ostream& operator<<(std::ostream & os, Type t);