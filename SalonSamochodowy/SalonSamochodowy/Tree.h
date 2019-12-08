#pragma once
#ifndef  TREE_H
#define TREE_H
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
#endif