#include <iostream>
#include <string>
#include <fstream>

static void copyReplaceData(std::string filename, std::ifstream file, std::string s1, std::string s2) {
	std::string newFilename = filename + ".replace";
	std::ofstream newFile(newFilename);
	
	if (!newFile) {
		std::cerr << "Cannot create the file" << std::endl;
		exit(1);
	}
	std::string line;
	while (getline(file, line)) {
		std::size_t pos = line.find(s1);
		if  (pos != std::npos) {
			//TODO add an array to find all of the occurances
		}
	}
}

int main(int ac, char *av[]) {
	if (ac != 4) {
		std::cerr << "Invalid number of arguments" << std::endl;
		return (1);
	}
	std::ifstream myfile;
	myfile.open(filename);

	if (!myfile) {
		std::cerr << "Cannot open the file" << std::endl;
		return (1);
	}


	myfile.close();
	return (0);
}