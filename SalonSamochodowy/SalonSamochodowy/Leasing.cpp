#include "Leasing.h"
#include "Model.h"
#include<fstream>
#include<sstream>
#include<iostream>

Leasing::Leasing()
	:
	amortization(0.01), constInterestRate(0.02), constMarkup(0.01),
	MileagesLimits({ 0, 10, 20, 30 }), Percentages({ 0.001, 0.005, 0.01, 0.05 })
{
	std::ifstream file("oprocentowanie.txt", std::ios_base::in);
	if (!file.good()) {
		std::cout << "Brak pliku oprocentowan\n";
		std::cout << "Nastapi uzycie domyslnych wartosci programu\n";
	}
	else {
		std::cout << "Pomyslnie otwarto plik leasing\n";
		std::string str;
		int line_num = 0;
		while (std::getline(file, str)) {
			++line_num;
			std::istringstream ss(str);
			if (line_num == 1)
				ss >> constInterestRate >> constMarkup >> amortization;
			else if (line_num == 2) {
				int num;
				MileagesLimits.clear();
				while (ss >> num)
					MileagesLimits.push_back(num);
			}
			else if (line_num == 3) {
				float num;
				Percentages.clear();
				while (ss >> num)
					Percentages.push_back(num);
			}
			else break;
		}
	}
	file.close();
	std::cout << constInterestRate<<' ';
	std::cout << constMarkup << ' ';
	std::cout << amortization << ' ';
	std::cout << "MILEAGES";
	for (auto i : MileagesLimits) std::cout << i << ';';
	std::cout << std::endl;
	std::cout << "PERCENTAGES";
	for (auto i : Percentages) std::cout << i << ';';

}
Leasing::Leasing(int _period, double _ownC, int _miles)
	:
	period(_period), ownContribution(_ownC), yearMileage(_miles){
	//zrobiæ konstruktor kopiuj¹cy w jakis sposob aby do glownego leasingu dorabial tylko powyzej zainicjalizowane dane *rzyg*
}

double Leasing::calculateTotalMarkup() {
	//obliczanie jak mam odczytane z pliku
	// odczyt gotowy, sprawdziæ czy metoda dzia³a prawid³owo
	int k = 1;
	std::cout << "MileagesLimits size =" << MileagesLimits.size() << ' ';
	while (k < (int)MileagesLimits.size()) {
		std::cout << "w petli, przebieg wynosi =" << yearMileage << ' ';
		if (yearMileage > MileagesLimits[k - 1]	&&
			yearMileage <= MileagesLimits[k]) {
			totalMarkup = ((double)constMarkup + Percentages[k - 1]);
			std::cout << "przebieg ze srodka =" << yearMileage << ' ';
		}
		else if (yearMileage > MileagesLimits[MileagesLimits.size() - 1]) { // 10k, 20k, 40k
			totalMarkup = ((double)constMarkup + Percentages[Percentages.size() - 1]);
			std::cout << "przebieg z konca =" << yearMileage << ' ';
		}
		k++;
	}
	return 1;
}

void Leasing::calculateMonthRate(Model *& m) {
	calculateTotalMarkup();
	finalBuyPrice = amortization * m->getPrice();
	annualInterestRate = constInterestRate + totalMarkup;
	r = annualInterestRate / (float)12; // oprocentowanie miesieczne
	ownContributionValue = m->getPrice() * ownContribution * (float)(100); //wartosc wkladu wlasnego
	monthRate = 
		( ( m->getPrice() - ownContributionValue ) * r * pow((1 + r), period) - finalBuyPrice * r)
		/
		(pow((1 + r), period) - 1);
}

std::ostream& operator << (std::ostream& os, Leasing l) {
	os.precision(2);
	os << "Miesieczna rata leasingu wynosi: ";
	os << l.totalMarkup << " << totalmarkup   ";
	os << l.monthRate;
	return os;
}