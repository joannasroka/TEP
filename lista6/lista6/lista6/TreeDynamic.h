#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "NodeDynamic.h"
#include "pch.h"
#include <queue>

using namespace std;

template <typename T> class TreeDynamic
{
public:
	TreeDynamic();
	~TreeDynamic();

	NodeDynamic<T>* getRoot();
	void printTree();

	bool moveSubtree(NodeDynamic<T>* parentNode, NodeDynamic<T>* newChildNode);

	bool sum(T* result);

	int nodesCount();

	void printTreeInBreadth(); // wypisywanie wszerz

	T* getMax();
private:
	NodeDynamic<T>* root;

};

template <typename T>
TreeDynamic<T>::TreeDynamic()
{
	NodeDynamic<T>* root = new NodeDynamic<T>();
	this->root = root;
}


template <typename T>
TreeDynamic<T>::~TreeDynamic()
{
	delete root;
}

template <typename T>
NodeDynamic<T> * TreeDynamic<T>::getRoot()
{
	return root;
}

template <typename T>
void TreeDynamic<T>::printTree()
{
	root->printAllBelow();
}

template <typename T>
bool TreeDynamic<T>::moveSubtree(NodeDynamic<T>* parentNode, NodeDynamic<T>* newChildNode)
{
	if ((*parentNode).getRoot() != this->getRoot()) return false; // sa w innych drzewach
	if ((*newChildNode).getRoot() == this->getRoot()) return false; // bo maja byc w innych drzewach

	newChildNode->getParent()->removeChild(newChildNode);
	parentNode->addNewChild(newChildNode);
	return true;
}
template <typename T>
bool TreeDynamic<T>::sum(T* result)
{
	return false;
}

template <>
bool TreeDynamic<int>::sum(int* result)
{
	root->sumAllBelow(result);
	return true;
}

template <>
bool TreeDynamic<double>::sum(double* result)
{
	root->sumAllBelow(result);
	return true;
}

template <>
bool TreeDynamic<string>::sum(string* result)
{
	root->sumAllBelow(result);
	return true;
}

template <typename T>
int TreeDynamic<T>::nodesCount()
{
	return root->nodesBelowCount();
}

template <typename T>
void TreeDynamic<T>::printTreeInBreadth()
{
	root->printAllBelowInBreadth();
}

template <typename T>
T* TreeDynamic<T>::getMax() {
	T* max = root->getValue();
	root->getMax(max);
	return max;
}






