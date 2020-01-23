#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<sstream>
#include "ReadFile.h"
#include "ReadModel.h"
#include "Body.h"
#include "Engine.h"
#include "Model.h"

ReadModelFile::ReadModelFile(std::string fname) : ReadFile(fname) {
	file.open(fileName, std::ios_base::in);
	if (file.good()) std::cout << "Pomyslnie otwarto plik " << fileName << std::endl;
	else std::cout << "error1\n";
}
ReadModelFile::~ReadModelFile() {
	file.close();
}
EQUIPMENT ReadModelFile::convertSegmentToEq(std::string segment) {
	if (segment == "Enjoy") return Enjoy;
	else if (segment == "Dynamic") return Dynamic;
	else if (segment == "Elite") return Elite;
	else return Unknown;
}
void ReadModelFile::GetModelFromLine(TreeOfEngines * root, ListOfModels * head) {

	while (std::getline(file, line))
	{
		/*std::cout << "LINE " << count++ << std::endl;
		std::cout << line << std::endl;*/

		dataSegments = SplitLine(line, ";");
		/*std::for_each(dataSegments.begin(), dataSegments.end(),
			[&count](std::string i) {
			std::cout <<'['<< count++ <<"] "<< i << ' ';
		}
		);*/

	//	std::cout << "lp: " << liczbaPetli++ << std::endl;
	//	std::cout << "wielkosc vectora: " << dataSegments.size() << std::endl;
		Body tmpBody = {
			dataSegments[9],
			std::stoi(dataSegments[10]),
			std::stoi(dataSegments[11]),
			std::stoi(dataSegments[12]),
			dataSegments[13],
			dataSegments[14],
		};

		//wydzielenie lokalizacji

		//konwersja enum
		EQUIPMENT eq = convertSegmentToEq(dataSegments[8]);
		
		//znalezienie silnika po nazwie i stworzenie wskaznika na ten obiekt w drzewie
		Engine * tmpEngine = root->search(dataSegments[15]);
		//std::cout << "Dodalem do modelu silnik: " << tmpEngine->getEngineName()<<std::endl;
		Model tmpModel(
			stoi(dataSegments[0]), //ID
			dataSegments[1], //model
			dataSegments[2], //generacja
			stoi(dataSegments[3]), //rok produkcji
			SplitLine(dataSegments[4], ","),//LOKALIZACJA DO VECTORA
			dataSegments[5],//transsmision type
			stoi(dataSegments[6]),//gears
			dataSegments[7], //drive
			dataSegments[15], //engineName
			tmpBody,
			tmpEngine,
			eq,
			stof(dataSegments[16]) //cena
		);
		//tmpModel.DisplayModelInfo();
		head->push(tmpModel);
	}
}


