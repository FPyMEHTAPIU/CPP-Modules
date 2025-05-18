#include "HumanB.hpp"

HumanB::~HumanB() {}

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {}

HumanB::HumanB(std::string name, Weapon& weapon):
	_name(name), _weapon(&weapon) {}

void HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

void HumanB::attack() {
	if (!_weapon) {
		std::cout << _name << " attacks with their knuckles" << std::endl;
		return ;
	}
	std::cout << _name << " attacks with their "
		<< _weapon->getType() << std::endl;
}