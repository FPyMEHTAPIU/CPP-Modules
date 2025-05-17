#pragma once
#include <iostream>

class Brain {
	private:
		std::string _ideas[100];
	
	public:
		Brain();
		Brain(Brain const& copy);
		~Brain();
		Brain& operator=(Brain const& brain);

		std::string getIdea(const int& index) const;
		void setIdea(const int& index, const std::string idea);
};