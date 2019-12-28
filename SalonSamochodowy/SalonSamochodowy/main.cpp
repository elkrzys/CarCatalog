#include<conio.h>
#include"Engine.h"
#include"Body.h"
#include"Model.h"
#include"ReadFile.h"
#include"ReadEngine.h"
#include"List.h"
#include"ReadModel.h"
#include"Tree.h"
#include"Leasing.h"
#include<iostream>



int main() {
	ListOfModels listOfCars;
	TreeOfEngines tree;

	ReadModelFile fileOfModels("spis_aut.csv");
	ReadEngineFile fileOfEngines("silniki.txt");

	Leasing calcLeasing;
	calcLeasing.ReadConstData("oprocentowanie.txt");

	
	fileOfEngines.MakeEnginesTree(tree);
	fileOfModels.GetModelFromLine(&tree, &listOfCars);
	listOfCars.displayElements();

	//kalkulacja leasingu, zrobic klase obslugi interfejsu
	//zeby mozna bylo wywolywac to niezaleznie
	// zebranie danych do leasingu
	// zebranie kryteriow wyszukiwania
	// wyswietlenie calej listy
	// elo koniec B)
	listOfCars.searchedModel(calcLeasing);

	
	_getch();
	return 0;
}