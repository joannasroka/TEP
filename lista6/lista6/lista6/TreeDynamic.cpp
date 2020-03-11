
/* 
#include "pch.h"
#include "TreeDynamic.h"

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
*/