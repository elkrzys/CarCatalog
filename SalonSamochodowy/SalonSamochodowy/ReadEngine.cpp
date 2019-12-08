#include<iostream>
#include<fstream>
#include<algorithm>

#include "ReadFile.h"
#include "ReadEngine.h"
#include "Tree.h"

ReadEngineFile::ReadEngineFile(std::string fname) : ReadFile(fname) {
	file.open(fileName, std::ios_base::in);
	if (file.good()) std::cout << "Pomyslnie otwarto plik\n";
	else std::cout << "error2\n";
}

ReadEngineFile::~ReadEngineFile() {
	file.close();
}

void ReadEngineFile::MakeEnginesTree(TreeOfEngines & tree) {
	while (std::getline(file, line)) {
		dataSegments = SplitLine(line, ",");

		Engine temp(
			dataSegments[0],
			dataSegments[3],
			std::stof(dataSegments[1]),
			std::stoi(dataSegments[2]),
			std::stof(dataSegments[4]),
			(std::stoi(dataSegments[5]) == 1) ? true : false
		);
		tree.insert(temp);
		
	}
}