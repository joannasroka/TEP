#include "pch.h"
#include "NodeStatic.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

NodeStatic::NodeStatic()
{
	value = 0;
	pParentNode = NULL;
}


NodeStatic::~NodeStatic()
{
	
}

NodeStatic::NodeStatic(NodeStatic* other)
{
	value = other->value;
	pParentNode = other->getParent();
	for (int i = 0; i < other->getChildrenNumber(); i++)
	{
		NodeStatic child(other->getChild(i));
		child.pParentNode = this;
		this->children.push_back(child);
	}
}

void NodeStatic::setValue(int newValue)
{
	value = newValue;
}

int NodeStatic::getChildrenNumber()
{
	return children.size();
}

void NodeStatic::addNewChild()
{
	NodeStatic child;
	child.pParentNode = this;
	children.push_back(child);

}

void NodeStatic::addNewChild(NodeStatic* child)// mozna &node
{
	children.push_back(*child);
	(*child).pParentNode = this;
}


NodeStatic * NodeStatic::getChild(int childOffset)
{
	if (childOffset >= children.size() || childOffset <0) return NULL;

	return &(children.at(childOffset));
}

void NodeStatic::print()
{
	cout << " " << value;
}

void NodeStatic::printAllBelow()
{
	print();

	for (vector <NodeStatic>::iterator i = children.begin(); i != children.end(); i++) {
		(*i).print();
	}
}


void NodeStatic::printUp()
{
	print();
	if (pParentNode != NULL) pParentNode->printUp();
}

NodeStatic * NodeStatic::getParent()
{
	return pParentNode;
}

NodeStatic * NodeStatic::getRoot()
{
	if (pParentNode != NULL) {
		return (*pParentNode).getRoot();
	}
	return this;
}

bool NodeStatic::removeChild(NodeStatic* child)
{
	for (int i = 0; i < this->getChildrenNumber(); i++) {
		if (this->getChild(i) == child) {
			children.erase(children.begin()+i);
			return true;
		}
	}
	return false;
}

int NodeStatic::getDeph()
{
	if (pParentNode != NULL) return 1 + pParentNode->getDeph();
	else return 0;
}






