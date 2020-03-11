#include "pch.h"
#include "TreeStatic.h"


TreeStatic::TreeStatic()
{
	NodeStatic defaultRoot;
	root = defaultRoot;
}


TreeStatic::~TreeStatic()
{
}

NodeStatic * TreeStatic::getRoot()
{
	return (&root);
}

void TreeStatic::printTree()
{
	root.printAllBelow();
}

	

bool TreeStatic::moveSubtree(NodeStatic * parentNode, NodeStatic * newChildNode)
{
	if ((*parentNode).getRoot() != this->getRoot()) return false; // sa w innych drzewach
	if ((*newChildNode).getRoot() == this->getRoot()) return false; // bo maja byc w innych drzewach
	NodeStatic newChild(newChildNode);
	parentNode->addNewChild(newChildNode);
	newChild.getParent()->removeChild(newChildNode);
	return true;
}

