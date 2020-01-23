#include"Engine.h"
#include<iostream>

Engine::Engine(std::string ename, std::string ftype,
	float cap, int hp, float fAvg, bool trb)
	:
	engineName(ename),
	fuelType(ftype),
	engineCapacity(cap),
	horsePower(hp),
	avgFuelConsumption(fAvg),
	turbo(trb),
	left(nullptr),
	right(nullptr)
{}
Engine::Engine(Engine* e) {
	this->engineName = e->engineName;
	this->fuelType = e->fuelType;
	this->engineCapacity = e->engineCapacity;
	this->horsePower = e->horsePower;
	this->avgFuelConsumption = e->avgFuelConsumption;
	this->turbo = e->turbo;
}
std::string Engine::getEngineName() const{
	return this->engineName;
}
std::ostream &operator << (std::ostream &os, const Engine &e) {
	os.precision(1);
	os << "\tPojemnosc: " << e.engineCapacity;
	os << " Rodzaj paliwa: " << e.fuelType << std::endl;
	os << "\tMoc: " << e.horsePower << "KM";
	os << " Srednie spalanie: " << e.avgFuelConsumption << " L/100km" << std::endl;
	if (e.turbo) os << "\tSilnik turbodoladowany";
	else os << "\tBez turbosprezarki";
	os << std::endl;
	return os;
}
std::string Engine::getFuelType() {
	return this->fuelType;
}
float Engine::getCapacity() {
	return this->engineCapacity;
}
int Engine::getHP() {
	return this->horsePower;
}