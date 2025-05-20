#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Marvin") {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Default constructor called! FragTrap Marvin created!"
		<< std::endl;
}

FragTrap::FragTrap(std::string name):
	ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << name << " created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap): ClapTrap(fragTrap) {
	std::cout << "FragTrap " << _name << " created by copy constructor!" << std::endl;
	*this = fragTrap;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << "FragTrap " << _name << " died and cannot attack!"
			<< std::endl;
		return ;
	} else if (_energyPoints == 0) {
		std::cout << "FragTrap " << _name << " is out of energy!"
			<< std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!"
		<< std::endl;
	_energyPoints--;
}

void FragTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "FragTrap " << _name << " died and cannot take damage!"
			<< std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " taken " << amount
		 << " points of damage!" << std::endl;
	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
}

void FragTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "FragTrap " << _name << " died and cannot heal!"
			<< std::endl;
		return ;
	} else if (_energyPoints == 0) {
		std::cout << "FragTrap " << _name << " is out of energy!"
			<< std::endl;
		return ;
	}
	else if (_hitPoints == 10) {
		std::cout << "FragTrap " << _name << " has full health!"
			<< std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " repaired " << amount
		 << " hit points!" << std::endl;
	_hitPoints += amount;
	if (_hitPoints > 10)
		_hitPoints = 10;
	_energyPoints--;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap) {
	if (this != &fragTrap) {
		ClapTrap::operator=(fragTrap);
	}
	return *this;
}

void FragTrap::status() const {
	std::cout << "FragTrap " << _name << " has " << _hitPoints << " hit points | "
		<< _energyPoints << " energy points | " << _attackDamage << " damage"
		<< std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << _name << " requests a positive high five! ✋" << std::endl;
}