#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "NodeDynamic.h"

using namespace std;

class TreeDynamic
{
public:
	TreeDynamic();
	~TreeDynamic();

	NodeDynamic* getRoot();
	void printTree();

	bool moveSubtree(NodeDynamic* parentNode, NodeDynamic* newChildNode);
private:
	NodeDynamic* root;

};

