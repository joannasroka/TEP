#pragma once
#include <iostream>
#define DEF_TAB_SIZE 10 
#include <string>

using namespace std;

class Table
{
public:
	Table();
	Table(const Table& other);
	Table(string fileLine, int size);
	Table(int newSize);
	Table(Table &&other);
	Table(double* pTable, int size);

	Table& operator=(const Table& other); // moze tu byc Tab& lub void
	Table& operator=(Table &&other); // Tab& lub void

	int epsilon(double x);

	double getCostU(double* table, int sizeY);
	double calculateProfit(double* table, int sizeX);
	bool setValueAt(double value, int index);

	bool getValueAt(double* value, int index);
	
	~Table();

	bool setSize(int newSize);
	int getSize() { return(size); }

	string toString();

private:
	void copy(const Table& other);
	void moveHelper(Table& other);

	double *pTable;
	int size;
};
