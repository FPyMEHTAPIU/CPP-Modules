#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main() {
	Zombie *zombie = newZombie("Mike");
	randomChump("Nick");
	randomChump("Carl");
	randomChump("Elly");

	delete zombie;
	return (0);
}