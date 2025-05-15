#pragma once
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& fragTrap);
		~FragTrap();

		FragTrap& operator=(const FragTrap& fragTrap);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void status() const;

		void highFivesGuys(void);
};