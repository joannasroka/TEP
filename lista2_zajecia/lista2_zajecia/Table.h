#pragma once
#include <string>

using namespace std;

class Table{
private: 
	string *name;
	int tableLen;
	int *pTable;

	string defaultName = "default";
	static int defaultTableLen;

public:
	Table();
	//~Table();
	Table(string name, int tableLen);
	Table(const Table &other);

	void setName(string newName);
	bool setNewSize(int newSize);
	Table *pClone();

	int getSize();

	void sum(Table &other);

	Table *pCloneReverse();

	void setValueAt(int offset, int newValue);

	void print();

	Table* operator+(Table &other);

	void operator=(const Table &other);

	Table* operator-(Table &other);

	bool isContain(int number);

	Table operator/(Table &other);

};

