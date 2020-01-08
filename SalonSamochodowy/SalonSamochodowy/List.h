#ifndef  LIST_H
#define LIST_H
#pragma once
#include "Model.h"
#include "Leasing.h"
class ListOfModels {
	
	int length;
public:
	Model* head;
	ListOfModels();
	void push(Model m); // dodawanie na koniec listy
	void deleteList();
	void displayElements();
	Model* searchedModel(Leasing l);
	~ListOfModels(); // destruktor usuwaj¹cy listê

	int getHeadID();
	void setHeadID();
};
#endif