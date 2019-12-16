#ifndef SEARCHMODEL_H
#define SEARCHMODEL_H
#pragma once
#include<string>
#include<map>

class SearchModel {
	//mapa - inty i double musza byc konwertowane przy szukaniu
	std::map<std::string, std::string> mapOfArgs;
	//ewentualnie lista parametrow jakby auto nie dzialalo
public:
	//setter argumentow - tworzy mape
	void SetArgs();
	//metoda wyszukiwania
	void Search(); // na razie bez zwracania, ale mozna zwracac liste lub jeden element
};

#endif 
