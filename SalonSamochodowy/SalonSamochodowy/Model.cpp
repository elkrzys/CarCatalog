#include<string>
#include<iostream>
#include "Engine.h"
#include "Body.h"
#include "Model.h"
#include<vector>

Model::Model(std::string mname, std::string gen, int yr, std::vector<std::string> loc,
	std::string trt, int grs, std::string drv, std::string ename, Body bdy,
	Engine *& engn, EQUIPMENT eq, float pr)
	:
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
	price(pr)
{}
void Model::DisplayModelInfo() const{
	std::cout.precision(2);
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