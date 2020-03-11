#include "pch.h"
#include <iostream>
#include "Table.h"
#include <cctype>
#include <algorithm>
#include <string>

using namespace std;

Table::Table()
{
	pTable = new double[DEF_TAB_SIZE];
	size = DEF_TAB_SIZE;
}

Table::Table(int newSize) 
{
	this->size = newSize;
	pTable = new double[size];
}

Table::Table(const Table &other)
{
	copy(other);
	//cout << "Copy ";
}

Table::Table(string fileLine, int size)
{
	// usuwanie bialych znakow
	fileLine.erase(remove_if(fileLine.begin(), fileLine.end(), ::isspace), fileLine.end());


	string delimiter = ";";
	this->size = size;

	pTable = new double[size];
	int index = 0;

	size_t pos = 0;
	string token;
	while ((pos = fileLine.find(delimiter)) != std::string::npos) {
		if (pos == 0) fileLine.erase(0, delimiter.length());
		else {
			token = fileLine.substr(0, pos);
			pTable[index] = stod(token);
			index++;
			fileLine.erase(0, pos + delimiter.length());
		}

		/*
		token = fileLine.substr(0, pos);
		pTable[index] = stod(token);
		index++;
		fileLine.erase(0, pos + delimiter.length());
	*/

	}
	
}

Table::Table (Table && other)
{
	this->moveHelper(other);
}

Table::Table(double * pTable, int size)
{
	this->pTable = pTable;
	this->size = size;
}


Table& Table ::operator=(const Table & other)
{
	//cout << "op= ";
	copy(other);
	return(*this);
}

Table& Table::operator=(Table && other)
{
	//cout << "op move= ";
	this->moveHelper(other);
	return (*this);
}

int Table::epsilon(double x)
{
	if (x > 0) return 1;
	else return 0;
}

double Table::getCostU(double * table, int sizeY)
{
	double result = 0.0;
	double rowSum = 0.0; // suma wiersza
	int tableIndex = 0;
	for (int x = 0; x < size; x++) {
		rowSum = 0.0;
		for (int y = 0; y < sizeY; y++) {
			rowSum += table[tableIndex];
			tableIndex++;
		}
		result += epsilon(rowSum) * pTable[x];
	}
	return result;
}

double Table::calculateProfit(double * table, int sizeX)
{
		double result = 0.0;
		int index = 0;
		for (int x = 0; x < sizeX; x++) {
			for (int y = 0; y < size; y++) {
				result += pTable[y] * table[index];
				index++;
			}

		}
		return result;
	
}

bool Table::setValueAt(double value, int index)
{
	if (index < 0 || index >= size) return false;
	pTable[index] = value;
	return true;
}

bool Table::getValueAt(double * value, int index)
{
	if ( index < 0 || index >= size) return false;
	//if (value != NULL) delete value;
	*value = (pTable[index]);
	return true;

}

Table::~Table()
{
	if (pTable != NULL) delete pTable;
	//cout << "Destr ";
}

bool Table::setSize(int newSize) // 1,2,3 newSize = 4
{
	if (size == newSize) return true;
	if (newSize <= 0) return false;

	int minSize;
	if (size < newSize) minSize = size; // minSize = 3
	else minSize = newSize;

	double* newTable = new double[newSize];

	for (int i = 0; i < minSize; i++) {
		newTable[i] = pTable[i];
	}

	delete[] pTable;
	pTable = newTable;
	size = newSize;
	return true;
}

string Table::toString()
{
	string result = "";

	for (int i = 0; i < size; i++) {
		result += to_string(pTable[i]);
		result += "; ;";
	}
	return result;
}

void Table::copy(const Table& other)
{
	if (pTable != NULL) delete[] pTable;
	//cout << "COPY ";
	pTable = new double[other.size];
	size = other.size;
	for (int i = 0; i < other.size; i++)
		pTable[i] = other.pTable[i];
}

void Table::moveHelper(Table& other)
{
	if (pTable != NULL) delete[] pTable;

	pTable = other.pTable;
	size = other.size;
	other.pTable = NULL;
	//cout << "MOVE ";
}
