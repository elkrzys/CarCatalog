#include"SearchModel.h"
#include<iostream>
//#include<typeinfo>
//#include<algorithm>
#include<string>
#include<conio.h>

SearchModel::SearchModel() : searchHead(nullptr) {}

void SearchModel::SetArgs() {

	std::string data;
	char k;
	std::cout << "Ponizej pojawia sie kryteria wyszukiwania." << std::endl;
	std::cout << "Aby wpisac odpowiednie kryterium nalezy po zapytaniu zatwierdzic klawiszem Enter" << std::endl;
	std::cout << "Aby pominac dane kryterium, nalezy nasisnac klawisz ESC" << std::endl << std::endl;

	std::cout << "Nazwa modelu ? (Enter / Esc) :/"<<std::endl;
//	k = std::cin.get();
	
	if (_getch() == 13) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Podaj model: ";
		std::getline(std::cin, data);
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		mapOfArgs.insert({ "model", data });
	}
	//fflush(stdin);
	
	
//	k = std::cin.get();
	std::cout << "Generacja ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Podaj generacje: ";
		std::getline(std::cin, data);
		mapOfArgs.insert({ "generation", data });
	}
//	fflush(stdin);
	//
	std::cout << "Lokalizacja ? (Enter wybor / Esc dowolna) :/" << std::endl;
	if (_getch() == 13) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Wybierz miasto | Krakow, Gliwice, Katowice lub Warszawa |: ";
		std::getline(std::cin, data);
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		mapOfArgs.insert({ "localization", data });
	}
	
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Rok produkcji ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Podaj rok produkcji: "; //stoi
		std::getline(std::cin, data);
	//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		mapOfArgs.insert({ "year", data });
	}
	
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Kolor nadwozia ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Podaj kolor: ";
		std::getline(std::cin, data);
	//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		mapOfArgs.insert({ "color", data });
	}
	
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Rodzaj paliwa ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		//k = getchar();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Rodzaj paliwa (benzyna / diesel): ";
		std::getline(std::cin, data);
	//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		mapOfArgs.insert({ "fuel", data });
	}
	
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Pojemnosc skokowa ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Podaj pojemnosc silnika: ";
		//std::getline(std::cin, data);
		std::cin >> data;
	//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		mapOfArgs.insert({ "capacity", data });
	}
	
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Moc silnika ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Podaj minimalna moc: ";
		//std::getline(std::cin, data);
		std::cin >> data;
	//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		mapOfArgs.insert({ "hp", data });
	}
	
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Rodzaj nadwozia ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Wybierz nadwozie: ";
		std::getline(std::cin, data);
	//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		mapOfArgs.insert({ "body", data });
	}
	
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Liczba drzwi ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Wybierz liczbe drzwi (3 / 4 / 5): ";
		//std::getline(std::cin, data);
		std::cin >> data;
	//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		mapOfArgs.insert({ "doors", data });
	}
	
//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Dolna granica cenowa ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Cena od: ";
		//std::getline(std::cin, data);
		std::cin >> data;
	//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		mapOfArgs.insert({ "botPrice", data });
	}
	else {
		mapOfArgs.insert({ "botPrice", "0" });
	}
	
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Gorna granica cenowa ? (Enter / Esc) :/" << std::endl;
	if (_getch() == 13) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Do: ";
		//std::getline(std::cin, data);
		std::cin >> data;
	//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		mapOfArgs.insert({ "topPrice", data });
	}
	else {
		mapOfArgs.insert({ "topPrice", "99999999" });
	}
}

void SearchModel::Search(ListOfModels * listHead) {
		
	ListOfModels * newList = listHead;
	searchHead = new ListOfModels;
	
	bool correct = false;
	while (newList->head) {
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
				if (std::stoi(itr->second) > newList->head->getEngine()->getHP()) correct = false;
			}
			//cena
			float botPrice = 0, topPrice = 999999999;
			if (itr->first == "botPrice") botPrice = stof(itr->second);
			if (itr->first == "topPrice") topPrice = stof(itr->second);
			if (newList->head->getPrice() < botPrice || newList->head->getPrice() > topPrice)
				correct = false;

			//std::cout << "CORRECT: " << correct << std::endl;
		}
		if (correct) {
			searchHead->push(*(newList->head));
			newList->head = newList->head->next;
		}
		else
			newList->head = newList->head->next;
	}
}
ListOfModels* SearchModel::getFoundElements() {
	return this->searchHead;
}
Model * SearchModel::SearchByID(ListOfModels* mainList, int ID){
	ListOfModels* newList = mainList;
	//Model* calculated = nullptr;
	while (newList->head) {
		if (newList->head->getID() == ID) {
			//calculated = newList->head;
			return newList->head;
			break;
		}
		else
			newList->head = newList->head->next;
	}
	return nullptr;
}