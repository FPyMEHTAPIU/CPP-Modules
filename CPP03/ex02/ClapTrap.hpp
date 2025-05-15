#pragma once
#include <iostream>

class ClapTrap {
	protected:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& clapTrap);
		virtual ~ClapTrap();
		ClapTrap& operator=(ClapTrap const& clapTrap);

		virtual void attack(const std::string& target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);

		void setDamage(const int damage);
		int	getDamage() const;
		int	getEnergy() const;
		std::string getName() const;
		void status() const;
};