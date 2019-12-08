#include "List.h"
#include<iostream>
ListOfModels::ListOfModels() {
	head = nullptr;
	length = 0;
}
void ListOfModels::push(Model m) {
	if (this->head == nullptr){
		head = new Model(m);
		head->next = nullptr;
	}
	else {
		Model * another = new Model(m);
		Model * tmp = head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = another;
		another->next = nullptr;
	}
}
void ListOfModels::deleteList() {
	if (!head) return;
	else {
		//int i = 1;
		Model * next;
		while (head) {
			//std::cout << "Usuwam element nr " << i++ <<std::endl;
			next = head->next;
			delete head;
			head = next;
		}
	}
}
void ListOfModels::displayElements() {
	if (!head) std::cout << "Pusta baza" << std::endl;
	else {
		Model * p = head;
		while (p) {
			p->DisplayModelInfo();
			std::cout << std::endl << std::endl;
			p = p->next;
		}
	}
}
Model * ListOfModels::searchedModel(Leasing l) {
	Model* temp = head;
	while (temp) {
		l = Leasing(36, 20, 20000);
		l.calculateMonthRate(temp);
		std::cout << l;
		std::cout << std::endl;
		temp = temp->next;
	}
	return nullptr;
}
ListOfModels::~ListOfModels() {
	deleteList();
}
