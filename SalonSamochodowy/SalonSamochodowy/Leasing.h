#pragma once
#ifndef LEASING_H
#define LEASING_H
#include"Model.h"
#include<vector>

class Leasing{
	double monthRate; // rata mieiesczna - wyliczenie
	int yearMileage; // roczny przebieg
	int period; // okres leasingu
	double amortization; // procent amortyzacji dla samochodu - do wyliczenia wartosci wykupu
	double finalBuyPrice;
	std::vector<double> Percentages;
	std::vector<int> MileagesLimits;
	double ownContribution; // wklad wlasny procentowo
	double ownContributionValue;
	double constMarkup; // stala marza
	double totalMarkup; //mar¿a zale¿na od przebiegu rocznego i okresu
	double constInterestRate; // stale oprocentowanie bankowe
	double annualInterestRate; // calkowite oprocentowanie roczne
	double r; // miesieczna rata oprocentowania
public:
	Leasing(); //konstruktor do stworzenia obiektu maj¹cego ju¿ dane dotycz¹ce oprocentowania i odczytane tablice przebiegów
	Leasing(int, double, int); // konstruktor wywo³ywany podczas faktycznego obliczania leasingu, przyjmuje okres, wklad w³asny i roczny przebieg
	double calculateTotalMarkup(); // wylicza totalMarkup zalezny od przbeigu i okresu
	void calculateMonthRate(Model *&);
	friend std::ostream& operator << (std::ostream& os, Leasing ); //wyswietlanie raty

};

#endif

