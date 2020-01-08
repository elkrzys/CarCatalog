#include"SearchModel.h"
#include<iostream>
//#include<typeinfo>
//#include<algorithm>
#include<string>
#include<conio.h>

SearchModel::SearchModel() : searchHead(nullptr), findModel(nullptr) {}

void SearchModel::SetArgs() {

	std::string data;
	std::cout << "Ponizej pojawia sie kryteria wyszukiwania." << std::endl;
	std::cout << "Aby wpisac odpowiednie kryterium nalezy po zapytaniu zatwierdzic klawiszem Enter" << std::endl;
	std::cout << "Aby pominac dane kryterium, nalezy nasisnac klawisz ESC" << std::endl << std::endl;

	std::cout << "Nazwa modelu ? (Enter / Esc) :/"<<std::endl;
	char k;
	if (_getch() == 13) {
		k = getchar();

		std::cout << "Podaj model: ";
		std::getline(std::cin, data);
		mapOfArgs.insert({ "model", data });
	}
	
	std::cout << "Generacja ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		k = getchar();
		std::cout << "Podaj generacje: ";
		std::getline(std::cin, data);
		mapOfArgs.insert({ "generation", data });
	}

	std::cout << "Lokalizacja ? (Enter wybor / Esc dowolna) :/" << std::endl;
	if (_getch() == 13) {
		k = getchar();
		std::cout << "Wybierz miasto: Krakow, Gliwice, Katowice lub Warszawa";
		std::getline(std::cin, data);
		mapOfArgs.insert({ "localization", data });
	}

	std::cout << "Rok produkcji ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		k = getchar();
		std::cout << "Podaj rok produkcji: "; //stoi
		std::getline(std::cin, data);
		mapOfArgs.insert({ "year", data });
	}

	std::cout << "Kolor nadwozia ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		k = getchar();
		std::cout << "Podaj kolor: ";
		std::getline(std::cin, data);
		mapOfArgs.insert({ "color", data });
	}

	std::cout << "Rodzaj paliwa ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		k = getchar();
		std::cout << "Rodzaj paliwa (benzyna / diesel): ";
		std::getline(std::cin, data);
		mapOfArgs.insert({ "fuel", data });
	}

	std::cout << "Pojemnosc skokowa ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		k = getchar();
		std::cout << "Podaj pojemnosc silnika: ";
		std::getline(std::cin, data);
		mapOfArgs.insert({ "capacity", data });
	}

	std::cout << "Moc silnika ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		k = getchar();
		std::cout << "Podaj moc: ";
		std::getline(std::cin, data);
		mapOfArgs.insert({ "hp", data });
	}

	std::cout << "Rodzaj nadwozia ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		k = getchar();
		std::cout << "Wybierz nadwozie: ";
		std::getline(std::cin, data);
		mapOfArgs.insert({ "body", data });
	}

	std::cout << "Liczba drzwi ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		k = getchar();
		std::cout << "Wybierz liczbe drzwi (3 / 4 / 5): ";
		std::getline(std::cin, data);
		mapOfArgs.insert({ "doors", data });
	}

	std::cout << "Dolna granica cenowa ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		k = getchar();
		std::cout << "Cena od: ";
		std::getline(std::cin, data);
		mapOfArgs.insert({ "botPrice", data });
	}
	else {
		mapOfArgs.insert({ "botPrice", "0" });
	}

	std::cout << "Gorna granica cenowa ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		k = getchar();
		std::cout << "Do: ";
		std::getline(std::cin, data);
		mapOfArgs.insert({ "topPrice", data });
	}
	else {
		mapOfArgs.insert({ "topPrice", "99999999" });
	}
	std::cout << "TU KONCZE, JEST OK 1" << std::endl;
}

void SearchModel::Search(ListOfModels * listHead) {
		
	ListOfModels * newList = listHead;
	searchHead = new ListOfModels;
	std::cout << "PRZED PETLA, JEST OK" << std::endl;
	bool correct = false;
	while (newList->head) {
		std::cout << "ID newList: " << newList->head->getID() << std::endl;
		std::cout << "TU WCHODZE, JEST OK" << std::endl;
		correct = true;
		for (auto itr = mapOfArgs.begin(); itr != mapOfArgs.end(); itr++) {
			//zapytania o model
			if (itr->first == "model" /*&& itr->second != "default"*/) {
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
			float botPrice = 0, topPrice = 999999999;
			if (itr->first == "botPrice") botPrice = stof(itr->second);
			if (itr->first == "topPrice") topPrice = stof(itr->second);
			if (newList->head->getPrice() < botPrice || newList->head->getPrice() > topPrice)
				correct = false;

			std::cout << "CORRECT: " << correct << std::endl;
		}
		if (correct) {
			searchHead->push(*(newList->head));
			newList->head = newList->head->next;
			std::cout << "DODAJE" << std::endl;
		}
		else
			newList->head = newList->head->next;
	}
	std::cout << "TU KONCZE, JEST OK 3" << std::endl;
}
ListOfModels* SearchModel::getFoundElements() {
	return this->searchHead;
}
Model SearchModel::SearchByID(ListOfModels* mainList, int ID){
	ListOfModels* newList = mainList;
	Model* calculated = nullptr;
	while (newList->head) {
		if (newList->head->getID() == ID) {
			calculated = newList->head;
			break;
			//newList->deleteList();
		}
		else
			newList->head = newList->head->next;
	}
	return *calculated;
}