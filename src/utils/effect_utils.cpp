// type_utils.cpp
#include "effect_utils.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include "../battle/move.h"

StatusEffect getEffectFromString(std::string s) {
    StatusEffect type;
    try {
        type = stringToEffect.at(s);
    } catch (const std::out_of_range& e) {
        std::cerr << "Invalid value requested from getEffectFromString: " << s << "\n";
        return StatusEffect::NONE;
    }
    return type;
}

std::string getStringFromEffect(StatusEffect t) {
    std::string string;
    try {
        string = effectToString.at(t);
    } catch (const std::out_of_range& e) {
        std::cerr << "Invalid value requested from getStringFromEffect: " << (int)t << "\n";
        return "";
    }
    return string;
}

std::ostream& operator<<(std::ostream & os, StatusEffect t) {
    os << getStringFromEffect(t);
    return os;
}