#include "pch.h"
#include "NodeDynamic.h"


NodeDynamic::NodeDynamic()
{
	value = 0;
	pParentNode = NULL;
}


NodeDynamic::~NodeDynamic()
{
	for (int i = 0; i < children.size(); i++) {
		delete children.at(i);
	} // dla kazdego uruchomi sie destruktor, a wiec dla dzieci dzieci tez
}

NodeDynamic::NodeDynamic(NodeDynamic* other) // niepotrzebne
{
	this->setValue(other->value);
	this->pParentNode = other->pParentNode;

	for (int i = 0; i < other->getChildrenNumber(); i++)
	{
		other->getChild(i)->pParentNode = this;
		this->children.push_back(new NodeDynamic(*(other->children.at(i))));
	}

}

void NodeDynamic::setValue(int newValue)
{
	value = newValue;
}

int NodeDynamic::getChildrenNumber()
{
	return children.size();
}

void NodeDynamic::addNewChild()
{
	NodeDynamic* child = new NodeDynamic();
	(*child).pParentNode = this;
	children.push_back(child);
}

void NodeDynamic::addNewChild(NodeDynamic * child)
{
	child->pParentNode = this;
	this->children.push_back(child);
}

NodeDynamic * NodeDynamic::getChild(int childOffset)
{
	if (childOffset >= children.size() || childOffset < 0) return NULL;

	return children.at(childOffset);
}

void NodeDynamic::print()
{
	cout << " " << value;
}

void NodeDynamic::printAllBelow()
{
	print();
	for (vector <NodeDynamic*>::iterator i = children.begin(); i != children.end(); i++) {
		(**i).printAllBelow();
	}
}


bool NodeDynamic::removeChild(NodeDynamic * node)
{
	for (int i = 0; i < this->getChildrenNumber(); i++) {
		if (this->getChild(i) == node) {
			children.erase(children.begin() + i);
			return true;
		}
	}
	return false;
}

NodeDynamic * NodeDynamic::getParent()
{
	return pParentNode;
}

NodeDynamic * NodeDynamic::getRoot()
{
	if (pParentNode != NULL) {
		return (*pParentNode).getRoot();
	}
	return this;
}
