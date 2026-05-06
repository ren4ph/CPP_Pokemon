#include "move_utils.h"
#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>

MoveKind getMoveKindFromString(std::string s) {
	try {
		return stringToMoveKind.at(s);
	} catch (const std::out_of_range &e) {
		std::cerr << "Invalid value requested from getMoveKindFromString: " << s
				  << "\n";
		return MoveKind::PHYSICAL;
	}
}

std::string getStringFromMoveKind(MoveKind k) {
	try {
		return moveKindToString.at(k);
	} catch (const std::out_of_range &e) {
		std::cerr << "Invalid value requested from getStringFromMoveKind: " << k
				  << "\n";
		return "";
	}
}

std::ostream &operator<<(std::ostream &os, MoveKind k) {
	return os << getStringFromMoveKind(k);
}
