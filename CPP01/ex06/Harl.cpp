#include "Harl.hpp"

Harl::HarlPTR Harl::_functions[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
std::string Harl::levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

void Harl::debug( void ) {
	std::cout << "I love playing the 8 string guitars!" << std::endl;
}

void Harl::info( void ) {
	std::cout << "8 string guitars cost more than 6 string ones, what a nonsense! 6 strings are not enough!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "I. NEED. MORE. STRINGS!!1!1" << std::endl;
}

void Harl::error( void ) {
	std::cout << "4 strings? That's not a guitar, wtf?!?" << std::endl;
}

void Harl::complain( std::string level ) {
	for (int i = 0; i < 4; ++i) {
		if (levels[i] == level) {
			std::cout << "[" << level << "]\n";
			(this->*_functions[i])();
			std::cout << std::endl;
			return ;
		}
	} 
}

void Harl::printLevels( std::string startLevel ) {
	int lvl = -1;
	for (int i = 0; i < 4; ++i) {
		if (levels[i] == startLevel) {
			lvl = i;
			break;
		}
	}
	switch (lvl) {
		case 0:
			complain("DEBUG");
			complain("INFO");
			complain("WARNING");
			complain("ERROR");
			break ;
		case 1:
			complain("INFO");
			complain("WARNING");
			complain("ERROR");
			break;
		case 2:
			complain("WARNING");
			complain("ERROR");
			break;
		case 3:
			complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

}