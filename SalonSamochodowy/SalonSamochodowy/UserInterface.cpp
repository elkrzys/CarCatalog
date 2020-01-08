#include"UserInterface.h"
#include"List.h"
#include"Model.h"
#include"Leasing.h"
#include"SearchModel.h"
#include<iostream>
#include<stdlib.h>

//UserInterface::UserInterface(ListOfModels &_mainList, SearchModel _search, Leasing _calc)  
//	: userChoice(0), mainList(_mainList), search(_search), Calculator(_calc) {};

void UserInterface::DisplayWelcome() {
	std::cout << " --- SALON SAMOCHODOWY OPEL --- " << std::endl;
	std::cout << " Obsluga doradztwa i leasingu samochodow osobowy " << std::endl;
	std::cout << std::endl << std::endl << std::endl;
}
void UserInterface::DisplayMainMenu() {
	std::cout << " --- MOZLIWE OPERACJE --- " << std::endl;
	std::cout << "\t[1] - PRZEGLAD CALEJ BAZY" << std::endl;
	std::cout << "\t[2] - ZNAJDZ SAMOCHOD" << std::endl;
	std::cout << "\t[3] - OBLICZ PRZEWIDYWANA RATE LEASINGU" << std::endl;
	std::cout << "\t[4] - DOWIEDZ SIE WIECEJ O WYPOSAZENIU" << std::endl;
	std::cout << "\t[9] - ZAKONCZ DZIALANIE" << std::endl;
	std::cout << "$$ Oczekiwanie na wybor: ";
	std::cout << std::endl << std::endl << std::endl;
}
void UserInterface::SearchMenu(SearchModel search, ListOfModels mainList) {
	std::cout << "Wprowadz dane do wyszukania" << std::endl << std::endl;

	search.SetArgs();
	std::cout << "USERINTERFACE PRZED WYWOLANIEM, JEST OK" << std::endl;
	search.Search(&mainList);
	std::cout << "PO WYWOLANIU" << std::endl;
	ListOfModels* allFound = search.getFoundElements();

	if (!allFound->head) {
		std::cout << "Brak znalezionych samochodow o wyroznionych kryteriach"<<std::endl;
		std::cout << "Sprobuj ponownie" << std::endl;
		return;
	}
	else {
		std::cout << "Znalezione samochody (zwroc uwage na ID do obliczenia leasingu lub przedstawienia szczegolow)" << std::endl << std::endl;
		allFound->displayElements();
	}
}
void UserInterface::LeaseMenu(SearchModel search, ListOfModels mainList, Leasing Calculator) const{
	int id;
	//ListOfModels* newList = &mainList;
	std::cout << " --- URUCHOMIONO KALKULATOR RATY LEASINGOWEJ --- " << std::endl;
	std::cout << "Wpisz ID wybranego modelu: ";
	std::cin >> id;
	if (id != (int)(id) || id == 0) {
		std::cout << "Podano bledny numer ID, sprobuj ponownie." << std::endl;
		LeaseMenu(search, mainList, Calculator);
	}
	else {
		Model toCalculate = search.SearchByID(&mainList, id);

		int mileage, period;
		float ownContr;

		std::cout << "KRYTERIA LEASINGU: roczny przebieg, okres leasingowania oraz wklad wlasny" << std::endl;
		std::cout << "Jaki bedzie roczny przebieg pojazdu? (do 10 000km, do 20 000km, do 30 000km lub powyzej)" << std::endl;
		std::cout << "Wprowadz przewidywany przebieg: ";
		std::cin >> mileage;
		while (mileage != (int)(mileage) || mileage < 0) {
			std::cout << "Bledne wskazanie przebiegu, sprobuj wprowadzic ponownie"<<std::endl;
			std::cin >> mileage;
		}

		std::cout << "Wybierz liczbe rat leasingu - 12, 24, 36 lub 60" << std::endl;
		std::cout << "Liczba rat: ";
		std::cin >> period;
		while (period != (int)period || period < 12 || period > 60) {
			std::cout << "Bledne wskazanie okresu leasingowania, sprobuj ponownie" << std::endl;
			std::cin >> period;
		}

		std::cout << "Wprowadz procent wkladu wlasnego [%]" << std::endl;
		std::cout << "Wklad wlasny (w %): ";
		std::cin >> ownContr;
		while (isnan(ownContr) || ownContr < 0 || ownContr > 100) {
			std::cout << "Blednie wprowadzony procent wkladu wlasnego, sprobuj ponownie" << std::endl;
			std::cin >> ownContr;
		}
		
		Calculator = Leasing(period, ownContr, mileage);
		Calculator.calculateMonthRate(toCalculate);
		std::cout << "OBLICZONE\n";
		
		std::cout << "Miesieczna rata leasingu dla wybranego modelu:" << std::endl;
		toCalculate.DisplayModelInfo();
		std::cout << std::endl;
		std::cout << "Oraz przy podanych patametrach: " << std::endl;
		std::cout << "Ilosc rat: " << period << " Przebieg: " << mileage << "Procent wkl. wlasn.: " << ownContr << std::endl;
		std::cout << "\tWynosi: " << Calculator;
	}
}
int UserInterface::MainMenu(ListOfModels * mainList, SearchModel search, Leasing Calculator) {
	std::cin >> userChoice;
	ListOfModels* operatingList = mainList;
	switch (userChoice) {
	case 1: {
		operatingList->displayElements();
		return 1;
	}
		break;
	case 2: {
		SearchMenu(search, *operatingList);
		return 2;
	}
		break;
	case 3: {
		LeaseMenu(search, *operatingList, Calculator);
		return 3;
	}
		break;
	case 4: {
		std::cout << "WYPOSAZENIE";
		return 4;
	}
		break;
	case 9: return 9;
		break;
	case 0:
	default:
	{
		system("cls");
		return 0;
	}
		break;
	}
}