#pragma once
#ifndef  READMODEL_H
#define READMODEL_H
#include"Model.h"
#include"List.h"
#include "Tree.h"
class ReadModelFile : public ReadFile {
public:
	ReadModelFile(std::string fname);
	~ReadModelFile();
	void GetModelFromLine(TreeOfEngines * root, ListOfModels * head);
	//std::vector<std::string> SetLocalization(std::string locSegment);
	EQUIPMENT convertSegmentToEq(std::string segment);
};
#endif