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
void Model::DisplayModelInfo() const{
	std::cout.precision(2);
	std::cout << "ID: " << this->id << std::endl;
	std::cout << this->modelName << ' ' << "price: " << std::fixed << this->price<< std::endl;
	std::cout << this->engine->getEngineName() << std::endl;
	for (auto &loc : this->localization) {
		std::cout << loc << ' ';
	}
	std::cout << std::endl;
	std::cout << *this->engine;
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
