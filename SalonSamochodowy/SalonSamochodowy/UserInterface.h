#ifndef USERINREFACE_H
#define USERINTERFACE_H
#pragma once

#include"List.h"
#include"Model.h"
#include"Leasing.h"
#include"SearchModel.h"

class UserInterface {
	int userChoice;
public:
	static void DisplayWelcome();
	void DisplayMainMenu();
	int MainMenu(ListOfModels*, SearchModel, Leasing);
	void SearchMenu(SearchModel, ListOfModels);
	void LeaseMenu(SearchModel, ListOfModels, Leasing) const;
	void EqMenu();
};
#endif