#include<string>
#include<iostream>
#include "Engine.h"
#include "Tree.h"
TreeOfEngines::TreeOfEngines() {
	root = nullptr;
}
TreeOfEngines::~TreeOfEngines() {
	destroyTree();
}
void TreeOfEngines::destroyTree(Engine * leaf) {
	if (leaf != nullptr) {
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
	}
}
void TreeOfEngines::destroyTree() {
	destroyTree(root);
}
void TreeOfEngines::insert(Engine e, Engine * leaf) {
	if (e.getEngineName() < leaf->getEngineName()) {
		if (leaf->left != nullptr)
			insert(e, leaf->left);
		else {
			leaf->left = new Engine(e);
			leaf->left->left = nullptr;
			leaf->left->right = nullptr;
		}
	}
	else if (e.getEngineName() >= leaf->getEngineName()) {
		if (leaf->right != nullptr)
			insert(e, leaf->right);
		else {
			leaf->right = new Engine(e);
			leaf->right->left = nullptr;
			leaf->right->right = nullptr;
		}
	}
}

void TreeOfEngines::insert(Engine e) {
	if (root != nullptr)
		insert(e, root);
	else {
		root = new Engine(e);
		root->left = nullptr;
		root->right = nullptr;
	}
	//std::cout << "dodalem do drzewa";
}

Engine *TreeOfEngines::search(std::string name, Engine * leaf) {
	if (leaf != nullptr) {
		if (name == leaf->getEngineName())
			return leaf;
		if (name < leaf->getEngineName())
			return search(name, leaf->left);
		else
			return search(name, leaf->right);
	}
	else
		return nullptr;
}

Engine *TreeOfEngines::search(std::string name) {
	return search(name, root);
}