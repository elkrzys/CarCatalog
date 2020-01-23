#include "ReadFile.h"
#include "EquipmentReader.h"
#include<string>
#include<iostream>
EquipmentReader::EquipmentReader(std::string fname) : ReadFile(fname) {}
void EquipmentReader::readAndDisplayEq() {
	file.open(fileName, std::ios_base::in);
	if (file.good()) {
		while (std::getline(file, line)) {
			std::cout << line << std::endl;
		}
		file.close();
	}
	else {
		std::cout << "Blad otwarcia pliku " << fileName << std::endl;
		file.close();
		return;
	}
	
}
void EquipmentReader::displayAllEq(std::string enjoy, std::string dynamic, std::string elite) {
	system("cls");

	fileName = enjoy;
	this->readAndDisplayEq();
	std::cout << "-------------------------------------------------------" << std::endl;

	fileName = dynamic;
	this->readAndDisplayEq();
	std::cout << "-------------------------------------------------------" << std::endl;

	fileName = elite;
	this->readAndDisplayEq();
	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << std::endl << std::endl;
}