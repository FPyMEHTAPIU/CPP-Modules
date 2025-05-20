#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static void check_attack(ClapTrap& attacker, ClapTrap& victim) {
	if (victim.getHitPoints() <= 0) {
		std::cout << "ClapTrap " << victim.getName() << " is dead!" << std::endl;
		return ;
	} else if (attacker.getEnergy() > 0) {
		attacker.attack(victim.getName());
		if (attacker.getHitPoints() <= 0)
			return ;
		victim.takeDamage(attacker.getDamage());
	} else
		attacker.attack(victim.getName());
}

static void check_attack_scavtrap(ScavTrap& attacker, ScavTrap& victim) {
	if (victim.getHitPoints() <= 0) {
		std::cout << "ScavTrap " << victim.getName() << " is dead!" << std::endl;
		return ;
	} else if (attacker.getEnergy() > 0) {
		attacker.attack(victim.getName());
		if (attacker.getHitPoints() <= 0)
			return ;
		victim.takeDamage(attacker.getDamage());
	} else
		attacker.attack(victim.getName());
}

static void check_attack_fragtrap(FragTrap& attacker, FragTrap& victim) {
	if (victim.getHitPoints() <= 0) {
		std::cout << "FragTrap " << victim.getName() << " is dead!" << std::endl;
		return ;
	} else if (attacker.getEnergy() > 0) {
		attacker.attack(victim.getName());
		if (attacker.getHitPoints() <= 0)
			return ;
		victim.takeDamage(attacker.getDamage());
	} else
		attacker.attack(victim.getName());
}

int main() {
	ClapTrap a("Mike"), b("Nick"), c("Duke");

	a.attack("Nick");
	b.takeDamage(a.getDamage());
	a.status();
	b.status();
	b.beRepaired(1);

	a.setDamage(2);
	check_attack(a, b);
	a.status();
	b.status();

	check_attack(c, a);
	c.status();
	a.status();

	c.setDamage(1);
	for (int i = 0; i < 12; ++i) {
		check_attack(c, a);
	}
	c.status();
	a.status();

	a.beRepaired(1);
	a.beRepaired(2);
	a.beRepaired(8);
	a.status();
	
	std::cout << "\nNow it's time to ScavTrap tests!\n";

	ScavTrap d("Joel"), f("Rick");

	check_attack_scavtrap(d, f);
	d.status();
	f.status();
	f.guardGate();
	check_attack_scavtrap(f, d);
	check_attack_scavtrap(f, d);
	check_attack_scavtrap(f, d);
	check_attack_scavtrap(f, d);
	check_attack_scavtrap(f, d);
	d.status();
	f.status();

	std::cout << "\nNow it's time to FragTrap tests!\n";

	FragTrap fr1("Sofia"), fr2("Clem");
	check_attack_fragtrap(fr1, fr2);
	check_attack_fragtrap(fr1, fr2);
	check_attack_fragtrap(fr1, fr2);
	check_attack_fragtrap(fr1, fr2);
	check_attack_fragtrap(fr2, fr1);
	fr1.status();
	fr2.status();
	fr2.highFivesGuys();

	return 0;
}