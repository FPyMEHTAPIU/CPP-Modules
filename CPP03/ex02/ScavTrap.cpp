#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("Marvin") {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Default constructor called! ScavTrap Marvin created!"
		<< std::endl;
}

ScavTrap::ScavTrap(std::string name):
	ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << name << " created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap): ClapTrap(scavTrap) {
	std::cout << "ScavTrap " << _name << " created by copy constructor!" << std::endl;
	*this = scavTrap;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << "ScavTrap " << _name << " died and cannot attack!"
			<< std::endl;
		return ;
	} else if (_energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " is out of energy!"
			<< std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!"
		<< std::endl;
	_energyPoints--;
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ScavTrap " << _name << " died and cannot take damage!"
			<< std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " taken " << amount
		 << " points of damage!" << std::endl;
	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ScavTrap " << _name << " died and cannot heal!"
			<< std::endl;
		return ;
	} else if (_energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " is out of energy!"
			<< std::endl;
		return ;
	}
	else if (_hitPoints == 10) {
		std::cout << "ScavTrap " << _name << " has full health!"
			<< std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " repaired " << amount
		 << " hit points!" << std::endl;
	_hitPoints += amount;
	if (_hitPoints > 10)
		_hitPoints = 10;
	_energyPoints--;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap) {
	if (this != &scavTrap) {
		ClapTrap::operator=(scavTrap);
	}
	return *this;
}

void ScavTrap::status() const {
	std::cout << "ScavTrap " << _name << " has " << _hitPoints << " hit points | "
		<< _energyPoints << " energy points | " << _attackDamage << " damage"
		<< std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " has entered Gate keeper mode." << std::endl;
}