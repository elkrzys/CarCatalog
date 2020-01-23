#include<string>
#include<iostream>
#include "Engine.h"
#include "Body.h"
#include "Model.h"
#include<vector>
#include<map>

Model::Model(int _id, std::string mname, std::string gen, int yr, std::vector<std::string> loc,
	std::string trt, int grs, std::string drv, std::string ename, Body bdy,
	Engine*& engn, EQUIPMENT eq, float pr)
	:
	id(_id),
	modelName(mname),
	generation(gen),
	yearOfProduction(yr),
	localization(loc),
	transmissionType(trt),
	gears(grs),
	drive(drv),
	engineName(ename),
	body(bdy),
	engine(engn),
	equipment(eq),
	price(pr),
	next(nullptr)
{}
void Model::DisplayModelInfo() const {
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout.precision(2);
	std::cout << "\t* Numer ID: " << this->id << " *" << std::endl;
	std::cout << '\t' << this->modelName << ' ' << this->generation << std::endl;
	std::cout << this->body;
	std::cout << "\tWersja wyposazenia: ";
		if (this->equipment == Enjoy) std::cout << "Enjoy";
			else if (this->equipment == Dynamic) std::cout << "Dynamic";
			else if (this->equipment == Elite) std::cout << "Elite";
			else if (this->equipment == Unknown) std::cout << "Nieznane";
		std::cout << std::endl;
	std::cout << '\t' << "Dostepny w: ";

	for (auto &loc : this->localization) {
		std::cout << loc << ' ';
	}

	std::cout << std::endl;
	std::cout << *this->engine;
	std::cout << '\t' << "Cena: " << std::fixed << this->price << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
}	
std::ostream& operator <<(std::ostream& out, const Model& m) {
	out << "\tModel ID: " << m.id << std::endl;
	out << '\t' << m.modelName << ' '<< m.generation << std::endl;
	out << m.body << std::endl;
	out << *m.engine << std::endl;
	return out;
}
float Model::getPrice() {
	return this->price;
}
std::string Model::getModelName() {
	return this->modelName;
}
std::string Model::getGen() {
	return this->generation;
}
Body* Model::getBody() {
	return &this->body;
}
Engine* Model::getEngine() {
	return this->engine;
}
std::vector<std::string> Model::getLoc() {
	return this->localization;
}
int Model::getYear() {
	return this->yearOfProduction;
}
int Model::getID() {
	return this->id;
}
