#include "ReadFile.h"
#include<fstream>
#include<string>
#include<iostream>


//std::istream & operator >> (std::istream & infile, std::string & line) {
//	if (infile.good() && std::getline(infile, line)) {
//		return infile;
//	}
//	std::cout << "line in istream: " << line << std::endl;
//	infile.clear(std::istream::eofbit | std::istream::failbit);
//	return infile;
//}

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