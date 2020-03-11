#pragma once
#include <iostream>
#include "NodeStatic.h"

using namespace std;

class TreeStatic
{
public:
	TreeStatic();
	~TreeStatic();

	NodeStatic* getRoot();
	void printTree();

	bool moveSubtree(NodeStatic* parentNode, NodeStatic* newChildNode);


private:
	NodeStatic root;
};

