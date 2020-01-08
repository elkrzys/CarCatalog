#ifndef SEARCHMODEL_H
#define SEARCHMODEL_H
#pragma once
#include<string>
#include<map>
#include"List.h"

class SearchModel {
	//mapa - inty i double musza byc konwertowane przy szukaniu
	std::map<std::string, std::string> mapOfArgs;
	ListOfModels* searchHead;
	ListOfModels* findModel;
	//ewentualnie lista parametrow jakby auto nie dzialalo
public:
	SearchModel();
	//setter argumentow - tworzy mape
	void SetArgs();
	//metoda wyszukiwania
	void Search(ListOfModels*);
	//zwrot listy
	ListOfModels* getFoundElements();
	//wyszukiwanie po ID
	Model SearchByID(ListOfModels*, int ID);

};

#endif 
