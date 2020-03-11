#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class NodeStatic
{
public:
	NodeStatic();
	~NodeStatic();
	NodeStatic(NodeStatic* other);

	void setValue(int newValue);
	int getChildrenNumber();
	void addNewChild();
	void addNewChild(NodeStatic* child);
	NodeStatic* getChild(int childOffset);
	void print();
	void printAllBelow();


	void printUp();

	NodeStatic* getParent();

	NodeStatic* getRoot(); // jezeli sa w tym samym drzewie to na pewno maja ten sam korzen

	bool removeChild(NodeStatic* child);

	int getDeph();

private:
	vector<NodeStatic> children;
	vector<NodeStatic> result;
	NodeStatic *pParentNode;
	int value;

};

