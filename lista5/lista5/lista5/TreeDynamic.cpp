#include "pch.h"
#include "TreeDynamic.h"


TreeDynamic::TreeDynamic()
{
	NodeDynamic* root = new NodeDynamic();
	this->root = root;
}


TreeDynamic::~TreeDynamic()
{
	delete root;
}

NodeDynamic * TreeDynamic::getRoot()
{
	return root;
}

void TreeDynamic::printTree()
{
	root->printAllBelow();
}

bool TreeDynamic::moveSubtree(NodeDynamic * parentNode, NodeDynamic * newChildNode)
{
	if ((*parentNode).getRoot() != this->getRoot()) return false; // sa w innych drzewach
	if ((*newChildNode).getRoot() == this->getRoot()) return false; // bo maja byc w innych drzewach

	newChildNode->getParent()->removeChild(newChildNode);
	parentNode->addNewChild(newChildNode);
	return true;
}
