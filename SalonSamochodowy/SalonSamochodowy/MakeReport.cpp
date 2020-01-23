#include "MakeReport.h"
#include<fstream>
#include<iostream>
MakeReport::MakeReport(std::string fname) : clientName("default"), clientSname("default"), day(0), month(day), year(day), clientPhoneNumber(day), ReadFile(fname) {
}
int MakeReport::setRepDetails(int p, int m, float c, float r) {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Wprowadz imie klienta:" << std::endl;
	std::cin >> this->clientName;
	std::cout << "Wprowadz nazwisko klienta:" << std::endl;
	std::cin >> this->clientSname;
	std::cout << "Wprowadz numer telefonu klienta:" << std::endl;
	std::cin >> this->clientPhoneNumber;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 11;
	}
	std::cout << "Wprowadz adres e-mail klienta:" << std::endl;
	std::cin >> this->email;
	std::cout << "Wprowadz date zlozenia oferty" << std::endl;
	std::cout << "Dzien: ";
	std::cin >> this->day;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 11;
	}
	std::cout << "Miesiac: ";
	std::cin >> this->month;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 11;
	}
	std::cout << "Rok: ";
	std::cin >> this->year;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 11;
	}

	period = p;
	mileage = m;
	ownc = c;
	rate = r;

	return 10;
}
void MakeReport::appNewReport(Model &m) {
	std::fstream file(fileName, std::ios_base::app);
	file << *this;
	file << "\tDane dotyczace oferowanego modelu" << std::endl << std::endl;
	file << m;
	file << "- - - - - - - - - - - - - -" << std::endl;
	file.close();
}
std::ostream& operator <<(std::ostream & out, MakeReport & rep) {
	out << "Oferta nr: " << rep.day << rep.month << rep.year % 2000 << rep.clientSname[0] << rep.clientName[0] << rep.email[1] << std::endl;
	out << "Data z³o¿enia oferty: " << rep.day << '-' << rep.month << '-' << rep.year << std::endl;
	out << "\tDane klienta:" << std::endl;
	out << "Imie: " << rep.clientName << ", Nazwisko: " << rep.clientSname << ", Numer telefonu : " << rep.clientPhoneNumber << std::endl;
	out << "Email: " << rep.email << std::endl;
	out << "Kryteria leasingowe:" << std::endl;
	out << "\tIlosc rat : " << rep.period << " Przebieg miesieczny : " << rep.mileage << " Wklad wlasny : " << rep.ownc << std::endl;
	out << "Proponowana rata: " << rep.rate << std::endl;

	return out;
}