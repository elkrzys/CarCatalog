#include<string>
#include<iostream>
#include"Body.h"

Body::Body(std::string t, int doors, int seats,
	int trunk, std::string clr, std::string sclr)
	:
	type(t),
	doors(doors),
	seats(seats),
	trunkCapacity(trunk),
	color(clr),
	specificColor(sclr)
{}
std::string Body::getColor() {
	return this->color;
}
std::string Body::getSpecificColor() {
	return this->specificColor;
}
std::string Body::getType() {
	return this->type;
}
int Body::getDoors() {
	return this->doors;
}
int Body::getSeats() {
	return this->seats;
}
int Body::getTrunk() {
	return this->trunkCapacity;
}
std::ostream& operator << (std::ostream& os, Body b) {
	os << "\tRodzaj nadwozia: " << b.type << std::endl;
	os << '\t' << b.color << " - " << b.specificColor << std::endl;
	os << "\tLiczba drzwi: " << b.doors << ",  " << b.seats << " miejsc" << std::endl;
	os << "\tPojemnosc bagaznika: " << b.trunkCapacity <<'L'<< std::endl;

	return os;
}