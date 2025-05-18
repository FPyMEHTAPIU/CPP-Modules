#include <iostream>
#include <string>
#include <fstream>

static void copyReplaceData(std::string filename, std::ifstream& file, std::string s1, std::string s2) {
	std::string newFilename = filename + ".replace";
	std::ofstream newFile(newFilename);
	
	if (!newFile) {
		file.close();
		std::cerr << "Cannot create the file" << std::endl;
		exit(1);
	}
	std::string line;
	while (getline(file, line)) {
		std::size_t start = 0;
		std::size_t pos;
		do {
			pos = line.find(s1, start);
			if (pos != std::string::npos) {
				newFile << line.substr(start, pos - start);
				newFile << s2;
				start = pos + s1.length();
			} else {
				newFile << line.substr(start);
			}
		}
		while (pos != std::string::npos);
		newFile << "\n";
	}
	newFile.close();
	file.close();
}

int main(int ac, char *av[]) {
	if (ac != 4) {
		std::cerr << "Invalid number of arguments" << std::endl;
		return 1;
	}
	std::string s1 = av[2], s2 = av[3];
	if (s1.empty() || s2.empty()) {
		std::cout << "Strings cannot be empty!" << std::endl;
		return 1;
	}
	std::ifstream myfile;
	myfile.open(av[1]);

	if (!myfile) {
		std::cerr << "Cannot open the file" << std::endl;
		return 1;
	}

	copyReplaceData(av[1], myfile, av[2], av[3]);
	return 0;
}