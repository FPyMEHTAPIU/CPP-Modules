#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

static void	announce_zombies(Zombie *zombies, int N) {
	for (int i = 0; i < N; ++i) {
		zombies[i].announce();
	}
}

int main() {
	Zombie *zombies = zombieHorde(3, "Mike");
	announce_zombies(zombies, 3);

	delete[] zombies;
	std::cout << "All zombies died before this line!" << std::endl;
	return (0);
}