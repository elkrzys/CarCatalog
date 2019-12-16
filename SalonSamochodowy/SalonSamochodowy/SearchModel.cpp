#include"SearchModel.h"
#include<iostream>

SearchModel::SearchModel() {}

void SearchModel::SetArgs() {
	std::string data;

	std::cout << "Podaj model: ";
	std::getline(std::cin, data);
	mapOfArgs.insert(std::pair < std::string, std::string>("model", data));

	std::cout << "Podaj rok produkcji: ";
	std::getline(std::cin, data);
	mapOfArgs.insert(std::pair < std::string, std::string>("rok produkcji", data));

	std::cout << "Podaj kolor: ";
	std::getline(std::cin, data);
	mapOfArgs.insert(std::pair < std::string, std::string>("kolor", data));

	std::cout << "Podaj pojemnosc silnika: ";
	std::getline(std::cin, data);
	mapOfArgs.insert(std::pair < std::string, std::string>("pojemnosc", data));

	std::cout << "Podaj moc: ";
	std::getline(std::cin, data);
	mapOfArgs.insert(std::pair < std::string, std::string>("moc", data));

}