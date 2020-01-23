#ifndef  ENGINE_H
#define ENGINE_H
#pragma once
#include<string>
class Engine
{
	std::string engineName;
	std::string fuelType;
	float engineCapacity;
	int horsePower;
	float avgFuelConsumption;
	bool turbo;
public:
	friend std::ostream &operator << (std::ostream &os, const Engine &e);
	std::string getEngineName() const;
	Engine(Engine *);
	Engine(std::string ename, std::string ftype,
		float cap, int hp, float fAvg, bool trb);
	~Engine() {};

	Engine *left, *right;

	std::string getFuelType();
	float getCapacity();
	int getHP();	
};
#endif