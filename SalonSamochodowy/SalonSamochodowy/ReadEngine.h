#pragma once
#ifndef READENGINE_H
#define READENGINE_H
#include<string>

#include"Engine.h"
#include "Tree.h"
class ReadEngineFile : public ReadFile {
public:
	ReadEngineFile(std::string fname);
	~ReadEngineFile();
	void MakeEnginesTree(TreeOfEngines &);
};
#endif