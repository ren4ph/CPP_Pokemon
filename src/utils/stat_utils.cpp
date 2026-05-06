#include "stat_utils.h"
#include <iostream>
#include <stdexcept>

StatType getStatTypeFromString(std::string s) {
	StatType st;
	try {
		st = statTypeFromString.at(s);
	} catch (const std::out_of_range &e) {
		std::cerr << "Invalid value requested from getStatTypeFromString: " << s
				  << "\n";
		return StatType::HP;
	}
	return st;
}

std::string getStringFromStatType(StatType st) {
	std::string string;
	try {
		string = stringFromStatType.at(st);
	} catch (const std::out_of_range &e) {
		std::cerr << "Invalid value requested from getStatTypeFromString: "
				  << st << "\n";
		return "";
	}
	return string;
}

std::ostream &operator<<(std::ostream &os, StatType st) {
	os << getStringFromStatType(st);
	return os;
}
