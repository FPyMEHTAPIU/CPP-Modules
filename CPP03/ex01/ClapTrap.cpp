#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Marvin"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor called! ClapTrap Marvin created!"
		<< std::endl;
}

ClapTrap::ClapTrap(std::string name):
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap) {
	std::cout << "ClapTrap " << _name << " created by copy constructor!" << std::endl;
	*this = clapTrap;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& clapTrap) {
	if (this != &clapTrap) {
		_name = clapTrap._name;
		_hitPoints = clapTrap._hitPoints;
		_energyPoints = clapTrap._energyPoints;
		_attackDamage = clapTrap._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " is out of energy!"
			<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!"
		<< std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " taken " << amount
		 << " points of damage!" << std::endl;
	_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " is out of energy!"
			<< std::endl;
		return ;
	}
	else if (_hitPoints == 10) {
		std::cout << "ClapTrap " << _name << " has full health!"
			<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " repaired " << amount
		 << " hit points!" << std::endl;
	_hitPoints += amount;
	if (_hitPoints > 10)
		_hitPoints = 10;
	_energyPoints--;
}

void ClapTrap::setDamage(const int damage) {
	_attackDamage = damage;
}

int	ClapTrap::getDamage() const {
	return _attackDamage;
}

int	ClapTrap::getEnergy() const {
	return _energyPoints;
}

std::string ClapTrap::getName() const {
	return _name;
}

void ClapTrap::status() const {
	std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points | "
		<< _energyPoints << " energy points | " << _attackDamage << " damage"
		<< std::endl;
}