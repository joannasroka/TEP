#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class NodeDynamic
{
public:
	NodeDynamic();
	~NodeDynamic();
	NodeDynamic(NodeDynamic* other);

	void setValue(int newValue);
	int getChildrenNumber();
	void addNewChild();
	void addNewChild(NodeDynamic* child);
	NodeDynamic* getChild (int childOffset); // w zadaniu bylo TreeDynamic* 
	void print();
	void printAllBelow();

	//void printWithPrefix(string prefix);

	bool removeChild(NodeDynamic* node);

	NodeDynamic* getParent();

	NodeDynamic* getRoot(); // jezeli sa w tym samym drzewie to na pewno maja ten sam korzen

private:
	vector <NodeDynamic*> children;
	NodeDynamic* pParentNode;
	int value;
};

