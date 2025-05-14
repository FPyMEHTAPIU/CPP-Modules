#pragma once
#include <iostream>

class Weapon {
	private:
		std::string _type;

	public:
		Weapon();
		Weapon(std::string weaponType);
		~Weapon();
		const std::string& getType();
		void setType(std::string type);
};