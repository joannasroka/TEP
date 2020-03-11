#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "pch.h"
#include <queue>

using namespace std;

template <typename T> class NodeDynamic
{
public:
	NodeDynamic();
	~NodeDynamic();
	NodeDynamic(NodeDynamic<T>* other);

	void setValue(T newValue);
	T* getValue();
	int getChildrenNumber();
	void addNewChild();
	void addNewChild(NodeDynamic<T>* child);
	NodeDynamic<T>* getChild(int childOffset); // w zadaniu bylo TreeDynamic* 
	void print();
	void printAllBelow();
	void printAllAbove();
	void printAllBelowInBreadth(); // wypisywanie wszerz

	bool removeChild(NodeDynamic* node);

	NodeDynamic<T>* getParent();

	NodeDynamic<T>* getRoot(); // jezeli sa w tym samym drzewie to na pewno maja ten sam korzen

	bool sumAllBelow(T* result);

	int nodesBelowCount();

	int getDegree(); // zwraca stopien danego node'a

	int getTreeDegree(vector<int> &nodesDegrees); // zwraca maksymalny stopien drzewa dla roota

	void getMax(T* oldMax);



private:
	vector <NodeDynamic<T>*> children;
	NodeDynamic<T>* pParentNode;
	T value;
};


template <typename T>
NodeDynamic<T>::NodeDynamic()
{
	//value = 0;
	pParentNode = NULL;
}

template <typename T>
NodeDynamic<T>::~NodeDynamic()
{
	for (int i = 0; i < children.size(); i++) {
		delete children.at(i);
	} // dla kazdego uruchomi sie destruktor, a wiec dla dzieci dzieci tez
}

template <typename T>
NodeDynamic<T>::NodeDynamic(NodeDynamic<T>* other) // niepotrzebne
{ /*
	this->setValue(other->value);
	this->pParentNode = other->pParentNode;

	for (int i = 0; i < other->getChildrenNumber(); i++)
	{
		other->getChild(i)->pParentNode = this;
		this->children.push_back(new NodeDynamic(*(other->children.at(i))));
	}
  */


}

template<typename T>
void NodeDynamic<T>::setValue(T newValue)
{
	value = newValue;
}

template<typename T>
T* NodeDynamic<T>::getValue()
{
	return &value;
}

template <typename T>
int NodeDynamic<T>::getChildrenNumber()
{
	return children.size();
}

template <typename T>
void NodeDynamic<T>::addNewChild()
{
	NodeDynamic<T>* child = new NodeDynamic<T>();
	(*child).pParentNode = this;
	children.push_back(child);
}

template <typename T>
void NodeDynamic<T>::addNewChild(NodeDynamic<T>* child)
{
	child->pParentNode = this;
	this->children.push_back(child);
}

template <typename T>
NodeDynamic<T> * NodeDynamic<T>::getChild(int childOffset)
{
	if (childOffset >= children.size() || childOffset < 0) return NULL;

	return children.at(childOffset);
}

template <typename T>
void NodeDynamic<T>::print()
{
	cout << " " << value;
}

template <typename T>
void NodeDynamic<T>::printAllBelow()
{
	print();
	for (typename vector <NodeDynamic<T>*>::iterator i = children.begin(); i != children.end(); i++) {
		(**i).printAllBelow();
	}
}


template <typename T>
void NodeDynamic<T>::printAllBelowInBreadth()
{
	int lastDegree = this->getDegree();
	queue<NodeDynamic<T>*> queueNodes;
	queueNodes.push(this);

	while (!queueNodes.empty()) {

		for (int i = 0; i < queueNodes.front()->getChildrenNumber(); i++) {
			queueNodes.push(queueNodes.front()->getChild(i));
		}

		if (queueNodes.front()->getDegree() > lastDegree) {
			cout << endl;
		}
		lastDegree = queueNodes.front()->getDegree();
		queueNodes.front()->print();
		queueNodes.pop();

	}
}

template <typename T>
void NodeDynamic<T>::printAllAbove()
{
	print();
	if (pParentNode != NULL) {
		(*pParentNode).printAllAbove();
	}

}


template <typename T>
bool NodeDynamic<T>::removeChild(NodeDynamic<T>* node)
{
	for (int i = 0; i < this->getChildrenNumber(); i++) {
		if (this->getChild(i) == node) {
			children.erase(children.begin() + i);
			return true;
		}
	}
	return false;
}

template <typename T>
NodeDynamic<T>* NodeDynamic<T>::getParent()
{
	return pParentNode;
}
template <typename T>
NodeDynamic<T>* NodeDynamic<T>::getRoot()
{
	if (pParentNode != NULL) {
		return (*pParentNode).getRoot();
	}
	return this;
}

template <typename T>
bool NodeDynamic<T>::sumAllBelow(T* result) {
	return false;
}

template <>
bool NodeDynamic<int>::sumAllBelow(int* result) {
	vector<int*> results;
	for (int i = 0; i < getChildrenNumber(); i++) {
		results.push_back(new int(0));
	}
	*result += this->value;

	for (int i = 0; i < getChildrenNumber(); i++) {
		children[i]->sumAllBelow(results[i]);
	}
	for (int i = 0; i < getChildrenNumber(); i++) {
		*result += *results[i];
	}

	return true;
}


template <>
bool NodeDynamic<double>::sumAllBelow(double* result) {
	vector<double*> results;
	for (int i = 0; i < getChildrenNumber(); i++) {
		results.push_back(new double(0));
	}
	*result += this->value;

	for (int i = 0; i < getChildrenNumber(); i++) {
		children[i]->sumAllBelow(results[i]);
	}
	for (int i = 0; i < getChildrenNumber(); i++) {
		*result += *results[i];
	}

	return true;
}


template <>
bool NodeDynamic<string>::sumAllBelow(string* result) {
	vector<string*> results;
	for (int i = 0; i < getChildrenNumber(); i++) {
		results.push_back(new string(""));
	}

	*result += this->value;
	*result += " ";

	for (int i = 0; i < getChildrenNumber(); i++) {
		children[i]->sumAllBelow(results[i]);
	}
	for (int i = 0; i < getChildrenNumber(); i++) {
		*result += *results[i];
	}
	return true;
}

template <typename T>
int NodeDynamic<T>::nodesBelowCount()
{
	int count = 1;
	for (typename vector <NodeDynamic<T>*>::iterator i = children.begin(); i != children.end(); i++) {
		count += (**i).nodesBelowCount();
	}
	return count;
}

template <typename T>
int NodeDynamic<T>::getDegree()
{
	int degree = 0;
	if (pParentNode != NULL) {
		degree += 1;
		degree += (*pParentNode).getDegree();
	}
	return degree;
}

template <typename T>
int NodeDynamic<T>::getTreeDegree(vector<int> &nodesDegrees)
{
	nodesDegrees.push_back(this->getDegree());
	for (int i = 0; i < this->getChildrenNumber(); i++) {
		this->getChild(i)->getTreeDegree(nodesDegrees);
	}
	int max = 0;
	for (int i = 0; i < nodesDegrees.size(); i++) {
		if (max < nodesDegrees[i]) max = nodesDegrees[i];
	}
	return max;
}

template <typename T>
void NodeDynamic<T>::getMax(T* oldMax) {
	if ((*oldMax) <= this->value) {
		(*oldMax) = this->value;
	}
	for (typename vector <NodeDynamic<T>*>::iterator i = children.begin(); i != children.end(); i++) {
		(**i).getMax(oldMax);
	}
}





