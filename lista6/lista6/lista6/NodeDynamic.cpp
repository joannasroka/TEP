/*
#include "pch.h"
#include "NodeDynamic.h"

template <typename T>
NodeDynamic<T>::NodeDynamic()
{
	value = 0;
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
{
	this->setValue(other->value);
	this->pParentNode = other->pParentNode;

	for (int i = 0; i < other->getChildrenNumber(); i++)
	{
		other->getChild(i)->pParentNode = this;
		this->children.push_back(new NodeDynamic(*(other->children.at(i))));
	}



template<typename T>
void NodeDynamic<T>::setValue(T newValue)
{
	value = newValue;
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
	for (vector <NodeDynamic<T>*>::iterator i = children.begin(); i != children.end(); i++) {
		(**i).printAllBelow();
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
 */