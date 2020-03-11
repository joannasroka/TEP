#include "pch.h"
#include "Table.h"
#include <iostream>

using namespace std;

Table::Table()
{
	cout << "konstruktor domyslny " << endl;
	pTab = new int*[DEF_SIZEX];
	for (int i = 0; i < DEF_SIZEX; i++) {
		pTab[i] = new int[DEF_SIZEY];
	}
	sizeX = DEF_SIZEX;
	sizeY = DEF_SIZEY;
}

Table::Table(int newSizeX, int newSizeY)
{
	if (newSizeX <= 0) sizeX = DEF_SIZEX;
	else sizeX = newSizeX;
	if (newSizeY <= 0) sizeY = DEF_SIZEY;
	else sizeY = newSizeY;

	cout << "konstruktor z parametrem: " << sizeX << ", " << sizeY << endl;

	pTab = new int*[sizeX];
	for (int i = 0; i < sizeX; i++) {
		pTab[i] = new int[sizeY];
	}

}

Table::Table(const Table & other)
{
	cout << "konstruktor kopiujacy " << endl;
	copy(other);
}

Table::Table(Table && other)
{
	cout << "konstuktor przenoszacy " << endl;
	moveHelper(other);
}

Table & Table::operator=(const Table & other)
{
	cout << "op= " << endl;
	copy(other);
	return(*this);
}

Table & Table::operator=(Table && other)
{
	cout << "op move= " << endl;
	this->moveHelper(other);
	return (*this);
}


Table::~Table()
{
	cout << " destruktor " << endl;
	if (pTab != NULL) {
		for (int i = 0; i < sizeX; i++) {
			delete[] pTab[i];
		}
		delete[] pTab;
	}
}

void Table::copy(const Table & other)
{
	if (pTab != NULL) {
		for (int i = 0; i < sizeX; i++) {
			delete[] pTab[i];
		}
		delete[] pTab;
	}
	cout << "kopiowanie " << endl;
	sizeX = other.sizeX;
	sizeY = other.sizeY;

	pTab = new int*[other.sizeX];
	for (int i = 0; i < sizeX; i++) {
		pTab[i] = new int[sizeY];
		for (int j = 0; j < sizeY; j++) {
			pTab[i][j] = other.pTab[i][j];
		}
	}


}

void Table::moveHelper(Table & other)
{
	if (pTab != NULL) {
		for (int i = 0; i < sizeX; i++) {
			delete[] pTab[i];
		}
		delete[] pTab;
	}

	pTab = other.pTab;
	sizeX = other.sizeX;
	sizeY = other.sizeY;

	other.pTab = NULL;

	cout << "przenoszenie " << endl;

}
