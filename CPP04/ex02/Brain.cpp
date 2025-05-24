#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const& copy) {
	*this = copy;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(Brain const& brain) {
	if (this != &brain) {
		for (int i = 0; i < 100; ++i) {
			_ideas[i] = brain._ideas[i];
		}
	}
	return *this;
}

std::string Brain::getIdea(const int& index) const {
	if (index < 0 || index >= 100) {
		std::cout << "Can't find any ideas on this place" << std::endl;
		return "";
	} else if (_ideas[index] == "") {
		std::cout << "Here's a free space for any ideas" << std::endl;
		return "";
	}
	return _ideas[index];

}

void Brain::setIdea(const int& index, const std::string idea) {
	if (index < 0 || index >= 100) {
		std::cout << "Can't store any ideas on this place" << std::endl;
		return ;
	}
	_ideas[index] = idea;
}