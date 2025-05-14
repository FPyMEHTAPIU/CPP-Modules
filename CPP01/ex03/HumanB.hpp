#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string _name;
		Weapon *_weapon;

	public:
		HumanB();
		HumanB(std::string name);
		~HumanB();
		void setWeapon(Weapon& weapon);
		void attack();
};