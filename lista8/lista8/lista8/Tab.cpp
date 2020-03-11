#include "pch.h"
#include <iostream>
#include "Tab.h"

using namespace std;

Tab::Tab()
{
	pTab = new int[DEF_TAB_SIZE];
	size = DEF_TAB_SIZE;
}

Tab::Tab(const Tab& other)
{
	copy(other);
	cout << "Copy ";
}

Tab::Tab(Tab && other)
{
	this->moveHelper(other);
}


Tab& Tab::operator=(const Tab & other)
{
	cout << "op= ";
	copy(other);
	return(*this);
}

Tab& Tab::operator=(Tab && other)
{
	cout << "op move= ";
	this->moveHelper(other);
	return (*this);
}

Tab::~Tab()
{
	if (pTab != NULL) delete pTab;
	cout << "Destr ";
}

bool Tab::setSize(int newSize) // 1,2,3 newSize = 4
{
	if (size == newSize) return true;
	if (newSize <= 0) return false;

	int minSize;
	if (size < newSize) minSize = size; // minSize = 3
	else minSize = newSize;

	int* newTab = new int [newSize];

	for (int i = 0; i < minSize; i++) {
		newTab[i] = pTab[i];
	}

	delete[] pTab;
	pTab = newTab;
	size = newSize;
	return true;
}

void Tab::copy(const Tab& other)
{
	if (pTab != NULL) delete[] pTab;
	cout << "COPY ";
	pTab = new int[other.size];
	size = other.size;
	for (int i = 0; i < other.size; i++)
		pTab[i] = other.pTab[i];
}

void Tab::moveHelper(Tab& other)
{
	if (pTab != NULL) delete[] pTab;

	pTab = other.pTab;
	size = other.size;
	other.pTab = NULL;
	cout << "MOVE ";
}
