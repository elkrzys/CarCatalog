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

	Leasing* calcLeasing = new Leasing();

	
	fileOfEngines.MakeEnginesTree(tree);
	fileOfModels.GetModelFromLine(&tree, &listOfCars);
	listOfCars.displayElements();

	listOfCars.searchedModel(*calcLeasing);

	
	_getch;
	return 0;
}