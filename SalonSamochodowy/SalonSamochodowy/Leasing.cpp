#include "Leasing.h"
#include "Model.h"
#include<fstream>
#include<sstream>
#include<iostream>

Leasing::Leasing()
	:
	//ustawiane/obliczane pozniej
	monthRate(0), annMileage(0), period(0), finalBuyPrice(0), ownContribution(0),
	ownContributionValue(0), totalMarkup(0), annualInterestRate(0), r(0),
	//moze byc w uzyciu przy blednym odczycie pliku
	amortization(0.01), constInterestRate(0.02), constMarkup(0.01), 
	MileagesLimits({ 0, 10000, 20000, 30000 }), Percentages({ 0.001, 0.005, 0.01, 0.05 })
{

}
//konstruktor na potrzebe przypisania wybranych przez uzytkownika danych
Leasing::Leasing(int _period, double _ownC, int _miles)
	:
	//konieczne do przypisania
	period(_period), ownContribution(_ownC/(double)100), annMileage(_miles),
	//nieuzywane
	monthRate(0), finalBuyPrice(0),
	ownContributionValue(0), totalMarkup(0), annualInterestRate(0), r(0),
	amortization(0.01), constInterestRate(0.02), constMarkup(0),
	MileagesLimits(0), Percentages(0)
{
}
Leasing& Leasing::operator=(Leasing l) {
	this->period = l.period;
	this->ownContribution = l.ownContribution;
	this->annMileage = l.annMileage;
	return *this;
}
void Leasing::ReadConstData(std::string filename) {
	std::ifstream file(filename, std::ios_base::in);
	if (!file.good()) {
		std::cout << "Brak pliku oprocentowan\n";
		std::cout << "Nastapi uzycie domyslnych wartosci programu\n"; //z konstruktora bezargumentowego
	}
	else {
		std::cout << "Pomyslnie otwarto plik leasing\n";
		std::string str;
		int line_num = 0;
		while (std::getline(file, str)) {
			++line_num;
			std::istringstream ss(str);
			//odczyt sta³ego oprocentowania, mar¿y i amortyzacji
			if (line_num == 1) {
				ss >> constInterestRate >> constMarkup >> amortization;
				constInterestRate /= (double)100;
				std::cout << constInterestRate << "constInterest z petli";
				constMarkup /= (double)100;
				amortization /= (double)100;
				std::cout << constMarkup << "const Markup z petli";
				std::cout << amortization << "amortization z petli";
			}
			//odczyt oprocentowania zaleznego od przebiegu
			else if (line_num == 2) {
				float num;
				Percentages.clear();
				while (ss >> num)
					Percentages.push_back(num / double(100));

			}
			//odczyt przbiegow ktore uzalezniaja oprocentowanie (przedzialy)
			else if (line_num == 3) {
				int num;
				MileagesLimits.clear();
				while (ss >> num)
					MileagesLimits.push_back(num);
			}
			else break;
		}
	}
	file.close();
}
void Leasing::calculateTotalMarkup() {
	int k = 0;
	//std::cout << "MileagesLimits size =" << MileagesLimits.size() << ' ';
	while (k < MileagesLimits.size()-1) {
		//std::cout << "w petli, przebieg wynosi =" << annMileage << ' ';
		//std::cout << "w petli, przebieg z VECTORA 0 i 1 wynosi =" << MileagesLimits[0] <<" i " << MileagesLimits[1] << ' ';
		if (annMileage > MileagesLimits[k]	&&
			annMileage <= MileagesLimits[k+1]) {
			totalMarkup = constMarkup + Percentages[k];
		//	std::cout << "przebieg ze srodka =" << annMileage << ' ';
		//	std::cout << totalMarkup << " -< TOTAL MARKUP w w IF\n";

		}
		if (annMileage > MileagesLimits[MileagesLimits.size() - 1]) { // 10k, 20k, 40k
			totalMarkup = constMarkup + Percentages[Percentages.size() - 1];
		//	std::cout << "przebieg z konca =" << annMileage << ' ';
		//	std::cout << totalMarkup << " -< TOTAL MARKUP w w IF222\n";
		}
		k++;
	}
	//std::cout << totalMarkup << " -< TOTAL MARKUP w metodzie\n";
}

void Leasing::calculateMonthRate(Model *& m) {
	calculateTotalMarkup();
	finalBuyPrice = amortization * m->getPrice();
	annualInterestRate = constInterestRate + totalMarkup;
	//std::cout << constInterestRate << ' ' << totalMarkup << "<- stale oprocentowanie i marza";
	//std::cout << annualInterestRate << "<- ROCZNE OPROCENTOWANIE";
	r = annualInterestRate / (double)12; // oprocentowanie miesieczne
	//std::cout << r << "<- MIESIECZNE OPROCENTOWANIE";
	ownContributionValue = m->getPrice() * ownContribution; //wartosc wkladu wlasnego
	std::cout << "\ncena: "<< m->getPrice() << std::endl;
	monthRate = 
		( ( m->getPrice() - ownContributionValue ) * r * pow((1 + r), period) - finalBuyPrice * r)
		/
		(pow((1 + r), period) - 1);
	//std::cout << monthRate<<"rata z metody\n";
}

std::ostream& operator << (std::ostream& os, Leasing l) {
	os.precision(2);
	os << "Miesieczna rata leasingu wynosi: ";
	os << l.monthRate;
	return os;
}

