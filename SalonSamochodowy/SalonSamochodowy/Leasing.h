#pragma once
#ifndef LEASING_H
#define LEASING_H
#include"Model.h"
#include<vector>

class Leasing{
	double monthRate; // rata mieiesczna - wyliczenie
	int annMileage; // roczny przebieg
	int period; // okres leasingu
	double amortization; // procent amortyzacji dla samochodu - do wyliczenia wartosci wykupu
	double finalBuyPrice;
	std::vector<double> Percentages; //stale oprocentowania zalezne od przedzialu przebiegu
	std::vector<unsigned int> MileagesLimits; //stale przebiegi w tysiacach
	double ownContribution; // wklad wlasny procentowo
	double ownContributionValue;
	double constMarkup; // stala marza
	double totalMarkup; //mar¿a zale¿na od przebiegu rocznego i okresu
	double constInterestRate; // stale oprocentowanie bankowe
	double annualInterestRate; // calkowite oprocentowanie roczne
	double r; // miesieczna rata oprocentowania
public:
	//konstruktor do stworzenia obiektu maj¹cego ju¿ dane dotycz¹ce oprocentowania i odczytane tablice przebiegów
	Leasing(); 
	// konstruktor wywo³ywany podczas faktycznego obliczania leasingu, przyjmuje okres, wklad w³asny i roczny przebieg
	Leasing(int, double, int); 
	//odczyt stalego oprocentowania i przebiegow z pliku
	void ReadConstData(std::string filename); 
	//konstruktor kopiujacy informacje z obiektu skonfigurowanego przez usera
	Leasing& operator=(Leasing);
	// wylicza totalMarkup zalezny od przbeigu i okresu
	void calculateTotalMarkup(); 
	//oblicza calkowita rate miesieczna z podanego modelu
	void calculateMonthRate(Model); 
	//wyswietlanie raty
	friend std::ostream& operator << (std::ostream& os, Leasing ); 
	

};

#endif

