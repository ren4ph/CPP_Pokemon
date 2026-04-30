// type_utils.cpp
#include "type_utils.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include "../battle/move.h"

Type getTypeFromString(std::string s) {
    Type type;
    try {
        type = stringToType.at(s);
    } catch (const std::out_of_range& e) {
        std::cerr << "Invalid value requested from getTypeFromString: " << s << "\n";
        return Type::NORMAL;
    }
    return type;
}

std::string getStringFromType(Type t) {
    std::string string;
    try {
        string = typeToString.at(t);
    } catch (const std::out_of_range& e) {
        std::cerr << "Invalid value requested from getStringFromType: " << t << "\n";
        return "";
    }
    return string;
}

std::string getTypePair(const Pokemon& p) {
    std::string result = getStringFromType(p.getPrimaryType());
    if (p.isDualType())
        result += "/" + getStringFromType(p.getSecondaryType());
    return result;
}

std::ostream& operator<<(std::ostream & os, Type t) {
    os << getStringFromType(t);
    return os;
}