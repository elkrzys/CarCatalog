#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <algorithm>
#include "Classes.h"

//FUNKCJE GLOBALNE
//konwersja string do enum
EQUIPMENT convertSegmentToEq(std::string segment) {
	if (segment == "Enjoy") return Enjoy;
	else if (segment == "Dynamic") return Dynamic;
	else if (segment == "Elite") return Elite;
	else return Unknown;
}


// KONSTRUKTORY, OPERATORY I METODY KLAS

// odczyt linii z pliku
//bool ReadFile::getLineFromFile() {
//	if (file.eof() || !file.good()) return false;
//	std::getline(file, line);
//	return true;
//}
std::istream & operator >> (std::istream &infile, std::string & line) {
	if (infile.good() && !infile.eof() && std::getline(infile, line)) {
			return infile;
	}
	infile.clear(std::istream::eofbit | std::istream::failbit);
	return infile;
}

// podzial lini na fragmenty gotowe do przypisania
std::vector<std::string> ReadFile::SplitLine(const std::string line, const std::string & delimiter) {
	std::vector<std::string> tmp;
	std::string::size_type position = 0;
	std::string::size_type prev = 0;
	while ((position = line.find(delimiter, prev)) != std::string::npos) {
		tmp.push_back(line.substr(prev, position - prev));
		prev = position + 1;
	}
	tmp.push_back(line.substr(prev));

	return tmp;
}

// odczyt pliku z modelami
ReadModelFile::ReadModelFile(std::string fname) : ReadFile(fname) {
	file.open(fileName, std::ios_base::in);
	if (file.good()) std::cout << "Pomyslnie otwarto plik\n";
	else std::cout << "error1\n";
}
ReadModelFile::~ReadModelFile() {
	file.close();
}
void ReadModelFile::GetModelFromLine() {
	int count = 0;
	int liczbaPetli = 1;
	std::vector<std::string> dataSegments;
	while (file >> line) //(file >> line
	{
		//std::cout << "LINE " << count++ << std::endl;
		//std::cout << line << std::endl;
		
		dataSegments = SplitLine(line, ";");
		/*std::for_each(dataSegments.begin(), dataSegments.end(),
			[&count](std::string i) {
			std::cout <<'['<< count++ <<"] "<< i << ' ';
		}
		);*/
		count = 0;
		std::cout << "lp: " << liczbaPetli++ << std::endl;
		std::cout << "wielkosc vectora: " << dataSegments.size() <<std::endl;
		Body tmpBody = {
			dataSegments[8],
			std::stoi(dataSegments[9]),
			std::stoi(dataSegments[10]),
			std::stoi(dataSegments[11]),
			dataSegments[12],
			dataSegments[13],
		};
		//konwersja enum
		EQUIPMENT eq = convertSegmentToEq(dataSegments[7]);


		//tymczasowe utworzenie obiektu engine 
		//do czasu zrobienia odczytu silnikow z pliku
		Engine tmpEngine("plname", "benzyna", 2.7, 1300, 6.4, false);
		Model tmpModel(
			dataSegments[0],
			dataSegments[1],
			std::stoi(dataSegments[2]),
			dataSegments[3],//lokalizacja do odczytu jeszcze
			dataSegments[4],//transsmision type
			std::stoi(dataSegments[5]),//gears
			dataSegments[6], //drive
			dataSegments[14], //engineName
			tmpBody,
			tmpEngine,
			eq,
			std::stof(dataSegments[15])
		);
		
		std::string a = dataSegments[0];
		std::cout << a << std::endl;
		//listOfEngines.add(tmpModel); <- dodanie do listy
		
	}
	
}

// odczyt pliku z silnikami
ReadEngineFile::ReadEngineFile(std::string fname) : ReadFile(fname) {
	file.open(fileName, std::ios_base::in);
	if (file.good()) std::cout << "Pomyslnie otwarto plik\n";
	else std::cout << "error2\n";
}

ReadEngineFile::~ReadEngineFile() {
	file.close();
}

//konstruktor klasy body
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



//konstruktor klasy Engine
Engine::Engine(std::string ename, std::string ftype, 
	float cap, int hp, float fAvg, bool trb) 
	:
	engineName(ename),
	fuelType(ftype),
	engineCapacity(cap),
	horsePower(hp),
	avgFuelConsumption(fAvg),
	turbo(trb)
{}
Engine::Engine(Engine* e) {
	this->engineName = e->engineName;
	this->fuelType = e->fuelType;
	this->engineCapacity = e->engineCapacity;
	this->horsePower = e->horsePower;
	this->avgFuelConsumption = e->avgFuelConsumption;
	this->turbo = e->turbo;
}
std::string Engine::getEngineName() {
	return this->engineName;
}

//konstruktor klasy Model
Model::Model(std::string mname, std::string gen, int yr, std::string loc,
	std::string trt, int grs, std::string drv, std::string ename, Body bdy,
	Engine engn, EQUIPMENT eq, float pr)
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

//drzewo silników, wyszukiwanie po nazwie
TreeOfEngines::TreeOfEngines() {
	root = nullptr;
}
TreeOfEngines::~TreeOfEngines() {
	destroyTree();
}
void TreeOfEngines::destroyTree(Engine * leaf) {
	if (leaf != nullptr) {
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
	}
}
void TreeOfEngines::destroyTree() {
	destroyTree(root);
}
void TreeOfEngines::insert(Engine e, Engine * leaf) {
	if (e.getEngineName() < leaf->getEngineName()) {
		if (leaf->left != nullptr)
			insert(e, leaf->left);
		else {
			leaf->left = new Engine(e);
			leaf->left->left = nullptr;
			leaf->left->right = nullptr;
		}
	}
	else if (e.getEngineName() >= leaf->getEngineName()) {
		if (leaf->right != nullptr)
			insert(e, leaf->right);
		else {
			leaf->right = new Engine(e);
			leaf->right->left = nullptr;
			leaf->right->right = nullptr;
		}
	}
}

void TreeOfEngines::insert(Engine e) {
	if (root != nullptr)
		insert(e, root);
	else {
		root = new Engine(e);
		root->left = nullptr;
		root->right = nullptr;
	}
}

Engine *TreeOfEngines::search(std::string name, Engine * leaf) {
	if (leaf != nullptr) {
		if (name == leaf->getEngineName())
			return leaf;
		if (name < leaf->getEngineName())
			return search(name, leaf->left);
		else
			return search(name, leaf->right);
	}
	else
		return nullptr;
}

Engine *TreeOfEngines::search(std::string name) {
	return search(name, root);
}