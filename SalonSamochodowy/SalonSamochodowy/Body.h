#ifndef  BODY_H
#define BODY_H
#include<string>
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

	std::string getColor();
	std::string getType();
	int getDoors();
};
#endif