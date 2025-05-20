#pragma once
#include <iostream>

class ClapTrap {
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& clapTrap);
		~ClapTrap();
		ClapTrap& operator=(ClapTrap const& clapTrap);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		int	getHitPoints() const;
		void setDamage(const int damage);
		int	getDamage() const;
		int	getEnergy() const;
		std::string getName() const;
		void status() const;
};