#include"SearchModel.h"
#include<iostream>
//#include<typeinfo>
//#include<algorithm>
#include<string>

SearchModel::SearchModel() : searchHead(nullptr) {}

void SearchModel::SetArgs() {

	std::string data;

	std::cout << "Podaj model: ";
	std::getline(std::cin, data);
	mapOfArgs.insert({"model", data});

	std::cout << "Podaj generacje: ";
	std::getline(std::cin, data);
	mapOfArgs.insert({ "generation", data });

	std::cout << "Wybierz miasto: Krakow, Gliwice, Katowice lub Warszawa";
	std::getline(std::cin, data);
	mapOfArgs.insert({ "localization", data });

	std::cout << "Podaj rok produkcji: "; //stoi
	std::getline(std::cin, data);
	mapOfArgs.insert({ "year", data });

	std::cout << "Podaj kolor: ";
	std::getline(std::cin, data);
	mapOfArgs.insert({ "color", data });

	std::cout << "Rodzaj paliwa (benzyna / diesel): ";
	std::getline(std::cin, data);
	mapOfArgs.insert({ "fuel", data });

	std::cout << "Podaj pojemnosc silnika: "; //stof
	std::getline(std::cin, data);
	mapOfArgs.insert({ "capacity", data });

	std::cout << "Podaj moc: "; // tu bedzie stoi
	std::getline(std::cin, data);
	mapOfArgs.insert({ "hp", data });

	std::cout << "Wybierz nadwozie: "; //type
	std::getline(std::cin, data);
	mapOfArgs.insert({ "body", data });

	std::cout << "Wybierz liczbe drzwi (3 / 4 / 5): ";
	std::getline(std::cin, data);
	mapOfArgs.insert({ "doors", data });

	std::cout << "Cena od: "; //tu bedzie stof
	std::getline(std::cin, data);
	mapOfArgs.insert({ "botPrice", data });

	std::cout << "Do: "; // tu bedzie stof
	std::getline(std::cin, data);
	mapOfArgs.insert({ "topPrice", data });

}

void SearchModel::Search(ListOfModels* listHead) {
	ListOfModels* newList = listHead;
	while (newList->head) {
		bool correct = true;
		for (auto itr = mapOfArgs.begin(); itr != mapOfArgs.end(); itr++) {
			//zapytania o model
			if (itr->first == "model" && itr->second != "default") {
				if (itr->second != newList->head->getModelName()) correct = false;
			}
			if (itr->first == "generation" && itr->second != "default") {
				if (itr->second != newList->head->getGen()) correct = false;
			}
			if (itr->first == "year" && std::stoi(itr->second) != 0) {
				if (std::stoi(itr->second) != newList->head->getYear()) correct = false;
			}
			if (itr->first == "localization" && itr->second != "default") {
				std::vector<std::string> loc = newList->head->getLoc();
				if (std::find(loc.begin(), loc.end(), itr->second) == loc.end()) correct = false;
			}
			//nadwozie
			if (itr->first == "color" && itr->second != "default") {
				if (itr->second != newList->head->getBody()->getColor()) correct = false;
			}
			if (itr->first == "body" && itr->second != "default") {
				if (itr->second != newList->head->getBody()->getType()) correct = false;
			}
			if (itr->first == "doors" && std::stoi(itr->second) != 0) {
				if (std::stoi(itr->second) != newList->head->getBody()->getDoors()) correct = false;
			}
			//silnik
			if (itr->first == "fuel" && itr->second != "default") {
				if (itr->second != newList->head->getEngine()->getFuelType()) correct = false;
			}
			if (itr->first == "capacity" && std::stof(itr->second) != 0) {
				if (std::stof(itr->second) != newList->head->getEngine()->getCapacity()) correct = false;
			}
			if (itr->first == "hp" && std::stoi(itr->second) != 0) {
				if (std::stoi(itr->second) != newList->head->getEngine()->getHP()) correct = false;
			}
			//cena
			float botPrice = 0, topPrice = 0;
			if (itr->first == "botPrice") botPrice = stof(itr->second);
			if (itr->first == "topPrice") topPrice = stof(itr->second);
			if (newList->head->getPrice() < botPrice || newList->head->getPrice() > topPrice)
				correct = false;

			if (correct) {
				searchHead->push(*(newList->head));
				newList->head = newList->head->next;
			}
			else 
				newList->head = newList->head->next;

		}
	}

}