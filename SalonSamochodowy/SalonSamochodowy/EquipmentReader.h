#ifndef EQUIPMENTREADER_H
#define EQUIPMENTREADER_H
#pragma once

#include "ReadFile.h"

class EquipmentReader : protected ReadFile {
public:
	EquipmentReader(std::string);
	void readAndDisplayEq();
	void displayAllEq(std::string, std::string, std::string);
};
#endif
