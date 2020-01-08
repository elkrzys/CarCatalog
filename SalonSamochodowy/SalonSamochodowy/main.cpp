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
#include"UserInterface.h"
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
	
	SearchModel search;
	//UserInterface Menu(listOfCars, search, calcLeasing);
	UserInterface::DisplayWelcome();
	int _returnedOption = 0;
	//UserInterface Menu(listOfCars, search, calcLeasing);
	UserInterface Menu;
	do {
		Menu.DisplayMainMenu();
		_returnedOption = Menu.MainMenu(&listOfCars, search, calcLeasing);
		std::cout << "W petli menu\n";
	} while (_returnedOption != 9);
	std::cout << "Wyszedlem" << std::endl;
	//Menu.DisplayMainMenu();
	//Menu.MainMenu();
	//listOfCars.displayElements();

	listOfCars.deleteList();
	_getch();
	return 0;
}