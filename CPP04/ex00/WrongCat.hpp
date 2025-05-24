#pragma once
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat const& cat);
		~WrongCat();
		WrongCat& operator=(WrongCat const& cat);
};