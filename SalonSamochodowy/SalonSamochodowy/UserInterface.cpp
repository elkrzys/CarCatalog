#include"UserInterface.h"
#include"List.h"
#include"Model.h"
#include"Leasing.h"
#include"SearchModel.h"
#include"EquipmentReader.h"
#include"MakeReport.h"
#include<iostream>
#include<stdlib.h>


void UserInterface::DisplayWelcome() {
	std::cout << std::endl;
	std::cout << " --- SALON SAMOCHODOWY OPEL --- " << std::endl;
	std::cout << " Obsluga doradztwa i leasingu samochodow osobowych " << std::endl;
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
	//config
	search.SetArgs();
	search.Search(&mainList);

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
	
	int id = 0;
	
	std::cout << " --- URUCHOMIONO KALKULATOR RATY LEASINGOWEJ --- " << std::endl << std::endl;
	std::cout << "Wpisz ID wybranego modelu: ";
	std::cin >> id;

	if (std::cin.fail() || id == 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "\n @ Podano bledny numer ID, sprobuj ponownie." << std::endl;
		return;
	}
	else {

		Model * toCalculate = search.SearchByID(&mainList, id);

		if (!toCalculate) {
			std::cout << "Brak znalezionego modelu" << std::endl;
			return;
		}

		int mileage, period;
		float ownContr;
		
		std::cout << std::endl;
		std::cout << "KRYTERIA LEASINGU: roczny przebieg, okres leasingowania oraz wklad wlasny" << std::endl << std::endl;
		std::cout << "Jaki bedzie roczny przebieg pojazdu? (do 10 000km, do 20 000km, do 30 000km lub powyzej)" << std::endl;
		std::cout << "Wprowadz przewidywany przebieg: ";

		std::cin >> mileage;

		while (std::cin.fail() || mileage < 0) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Bledne wskazanie przebiegu, sprobuj wprowadzic ponownie"<<std::endl;
			std::cin >> mileage;
		}

		std::cout << "Wybierz liczbe rat leasingu - 12, 24, 36 lub 60" << std::endl;
		std::cout << "Liczba rat: ";
		std::cin >> period;

		while (std::cin.fail() || 
				period != 12 && 
					period != 24 && 
						period != 36 && 
							period != 60) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Bledne wskazanie okresu leasingowania, sprobuj ponownie" << std::endl;
			std::cin >> period;
		}

		std::cout << "Wprowadz procent wkladu wlasnego [%] (od 0 do 30)" << std::endl;
		std::cout << "Wklad wlasny (w %): ";
		std::cin >> ownContr;
		while (std::cin.fail() || 
				ownContr < 0 || ownContr > 30) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Blednie wprowadzony procent wkladu wlasnego, sprobuj ponownie" << std::endl;
			std::cin >> ownContr;
		}
		
		Calculator = Leasing(period, ownContr, mileage);
		Calculator.calculateMonthRate(*toCalculate);
		
		//wypisanie
		system("cls");
		std::cout << "Dla wybranego modelu:" << std::endl;
		toCalculate->DisplayModelInfo();

		std::cout << std::endl;
		std::cout << "Oraz przy podanych patametrach: " << std::endl;
		std::cout << "Ilosc rat: " << period << 
			", Roczny przebieg: " << mileage << "km," << 
			" Wklad wlasn.: " << ownContr << '%' << 
			std::endl << std::endl;

		std::cout << "\t-------------------------------------------------"<<std::endl;
		std::cout << "\t*** " << Calculator << " ***" << std::endl;
		std::cout << "\t-------------------------------------------------" << std::endl;
		std::cout << std::endl << std::endl;

		//wpisanie do raportu
		std::cout << "Dodac zamowienie do raportu? t/n - tak/nie" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		char tn = getchar();
		if (tn == 't' || tn == 'T') {
			MakeReport report("oferty.txt");
			int valid = report.setRepDetails(period, mileage, ownContr, Calculator.getMonthRate());
			if (valid == 10) {
				report.appNewReport(*toCalculate);
				std::cout << "Dodano oferte do zestawienia, poinformuj klienta" << std::endl;
			}
			else {
				std::cout << "Bledne dane [Err 11]" << std::endl;
			}
		}
		else std::cout << "Pominieto dodawanie zamowienia" << std::endl;
	}
}

void UserInterface::EqMenu() {
	std::cout << std::endl;
	std::cout << "--- Wyposazenie ---" << std::endl;
	std::cout << "Opis i porownanie wyposazenia samochodu" << std::endl;
	
	std::cout << "\t[1] - Pakiet Enjoy" << std::endl;
	std::cout << "\t[2] - Pakiet Dynamic" << std::endl;
	std::cout << "\t[3] - Pakiet Elite" << std::endl;
	std::cout << "\t[4] - Porownaj wszystkie" << std::endl;
	std::cout << "\t[9] - Powrot" << std::endl << std::endl;

	int choice;
	std::cout << "Wybierz opcje:" << std::endl;
	std::cin >> choice;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Bledny wybor, powrot" << std::endl << std::endl;
		return;
	}
	else {
		switch (choice) {
		case 1: {
			EquipmentReader readEq("wyposazenie/enjoy.txt");
			readEq.readAndDisplayEq();
		}
			break;
		case 2: {
			EquipmentReader readEq("wyposazenie/dynamic.txt");
			readEq.readAndDisplayEq();
		}
			break;
		case 3: {
			EquipmentReader readEq("wyposazenie/elite.txt");
			readEq.readAndDisplayEq();
		}
			break;
		case 4: {
			EquipmentReader readEq("");
			readEq.displayAllEq("wyposazenie/enjoy.txt", "wyposazenie/dynamic.txt", "wyposazenie/elite.txt");
		}
			break;
		case 9:
			std::cout << "Anulowano" << std::endl << std::endl;
			break;
		default:
			std::cout << "Bledny wybor, powrot" << std::endl << std::endl;
			return;
			break;
		}
	}
}
int UserInterface::MainMenu(ListOfModels * mainList, SearchModel search, Leasing Calculator) {
	
	std::cin >> userChoice;

	if (std::cin.fail()) {
		std::cout << "Bledny wybor, sprobuj ponownie" << std::endl << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("cls");
		return 0;
	}

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
		EqMenu();
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