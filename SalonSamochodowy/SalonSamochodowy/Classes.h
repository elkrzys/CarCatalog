#ifndef  CLASSES_H
#define CLASSES_H
#include<vector>
enum EQUIPMENT { Enjoy, Dynamic, Elite, Unknown };

// silnik
class Engine
{
	std::string engineName;
	std::string fuelType;
	float engineCapacity;
	int horsePower;
	float avgFuelConsumption;
	bool turbo;
public:
	void DisplayEngineInfo();
	std::string getEngineName();
	Engine(Engine *);
	Engine(std::string ename, std::string ftype,
		float cap, int hp, float fAvg, bool trb);
	~Engine() {};
	Engine *left, *right;
};

// nadwozie samochodu
class Body {
	std::string type; //hatch, combi, sedan
	int doors; // 3, 5
	int seats; // 2/4/5
	int trunkCapacity; //340,600 etc..
	std::string color; //niebieski
	std::string specificColor; //darkmoon
public:
	Body(std::string, int, int, int, std::string, std::string);
	~Body() {};

};

//klasa sk³adowa modelu
class Model {
	std::string modelName;
	std::string generation;
	int yearOfProduction;

	//std::vector<std::string> localization; //tablica salonow w ktorych jest dostepny
	std::string localization;

	std::string transmissionType; //automat lub manual
	int gears;
	std::string drive; // awd, fwd, rwd
	std::string engineName;

	Body body;
	Engine engine;
	//Engine * pointerToEngine;
	EQUIPMENT equipment;

	float price;

public:
	void DisplayModelInfo() const; // wyswietla wszystkie informacje o samochodzie
	Model(std::string mname, std::string gen, int yr, std::string loc,
		std::string trt, int grs, std::string drv, std::string ename, Body bdy,
		Engine engn, EQUIPMENT eq, float pr);
	~Model() {};

	//wskaznik na nastepny element - potrzebne do listy
	Model * next;

};

class ListOfModels {
	Model *head;
	int length;
public:
	ListOfModels() {
		head = nullptr;
		length = 0;
	}
	void push(); // dodawanie na koniec listy
	~ListOfModels(); // destruktor usuwaj¹cy listê
};
class TreeOfEngines {
	Engine * root;

	void destroyTree(Engine*);
	void insert(Engine, Engine*);
	Engine *search(std::string, Engine*);
public:
	TreeOfEngines();
	~TreeOfEngines();

	void insert(Engine);
	Engine *search(std::string);
	void destroyTree();

};

class ReadFile {
protected:
	std::string fileName;
	std::string line;
	std::fstream file;
public:
	ReadFile(std::string fname) : fileName(fname) {};

	std::string getFileName();
	//bool getLineFromFile();
	friend std::istream & operator >> (std::istream &, std::string &);
	std::vector<std::string> SplitLine (const std::string, const std::string &);
};

class ReadModelFile : public ReadFile {
public:
	ReadModelFile(std::string fname);
	~ReadModelFile();
	void GetModelFromLine();
};

class ReadEngineFile : public ReadFile {
public:
	ReadEngineFile(std::string fname);
	~ReadEngineFile();
	void ReadEngineFromLine(std::string engineName, Engine & e);
};
#endif

