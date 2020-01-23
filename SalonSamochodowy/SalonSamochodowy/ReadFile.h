#pragma once
#ifndef  READFILE_H
#define READFILE_H
#include<vector>
#include<fstream>
class ReadFile {
protected:
	std::string fileName;
	std::string line;
	std::fstream file;
	std::vector<std::string> dataSegments;
public:
	ReadFile(std::string fname) : fileName(fname) {};

	std::string getFileName(); //moze sie przydac
	
	std::vector<std::string> SplitLine(const std::string, const std::string &);
};
#endif