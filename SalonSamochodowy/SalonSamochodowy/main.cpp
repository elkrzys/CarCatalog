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
	
	fileOfEngines.MakeEnginesTree(tree);
	fileOfModels.GetModelFromLine(&tree, &listOfCars);
	
	Leasing calcLeasing;
	calcLeasing.ReadConstData("oprocentowanie.txt");

	SearchModel search;
	UserInterface::DisplayWelcome();
	int _returnedOption = 0;

	UserInterface Menu;
	do {
		Menu.DisplayMainMenu();
		_returnedOption = Menu.MainMenu(&listOfCars, search, calcLeasing);
	} while (_returnedOption != 9);

	listOfCars.deleteList();
	
	return 0;
}