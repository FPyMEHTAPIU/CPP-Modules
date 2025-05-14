#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType): _type(weaponType) {}

Weapon::Weapon(): _type("knuckles") {}
Weapon::~Weapon() {}

const	std::string& Weapon::getType() {
	return (_type);
}

void	Weapon::setType(std::string type) {
	_type = type;
}