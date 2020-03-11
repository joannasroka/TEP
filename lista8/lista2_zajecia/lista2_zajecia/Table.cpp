#include "pch.h"
#include "Table.h"
#include <iostream>

//string Table::defaultName = "Default";
int Table::defaultTableLen = 10;

Table::Table(){
	name = new string(defaultName);
	tableLen = defaultTableLen;
	cout << "bezp: " << *name << endl;
	pTable = new int[tableLen];

}

Table::~Table(){

	
	if(pTable != NULL) delete[] pTable;
	if (name != NULL) {
		cout << "usuwam: " << *name << endl;
		delete name;
	}
	else cout << "usuwam pusty " ;
} 

Table::Table(string newName, int newTableLen) {
	
	name = new string(newName);
	tableLen = newTableLen;
	cout << "parametr: " << *name << endl;
	pTable = new int[tableLen];
}

Table::Table(const Table & other){
	name = new string(*other.name + "_copy");
	tableLen = other.tableLen;
	pTable = new int[tableLen];
	for (int i = 0; i < tableLen; i++){
		pTable[i] = other.pTable[i];
	}
	cout << "kopiuj: " << *name << endl;
}

Table::Table(Table&& other) {
	this->moveHelper(other);
	cout << "tworze przenoszac: " << *name << endl;
}

void Table::setName(string newName){
	//delete name;
	*name = newName;
}

bool Table::setNewSize(int newTableLen){
	if (newTableLen <= 0) return false;
	int *newPTable = new int[newTableLen];
	int minTableLen = (newTableLen < tableLen) ? newTableLen : tableLen;
	for (int i = 0; i < minTableLen; i++) {
		newPTable[i] = pTable[i];
	}
	delete[] pTable;
	pTable = newPTable;
	tableLen = newTableLen;
	return true;
}

Table Table::pClone(){
	return move(Table(*this));
}

int Table::getSize(){
	return tableLen;
}

void Table::sum(Table & other){
	int *newPTable = new int[other.tableLen + this->tableLen];
	for (int i = 0; i < this->tableLen; i++) {
		newPTable[i] = this->pTable[i];
	}
	for (int j = 0; j < other.tableLen; j++) {
		newPTable[this->tableLen+j] = other.pTable[j];
	}
	delete pTable;
	pTable = newPTable;
	tableLen = tableLen + other.tableLen;
}

Table Table::pCloneReverse(){
	Table newTable (*this);
	for (int i = 0; i++; i < this->tableLen) {
		newTable.pTable[this->tableLen - 1 - i] = this->pTable[i];
	}
	return move(newTable);
}

void Table::setValueAt(int offset, int newValue){
	if (offset >= tableLen) return;
	pTable[offset] = newValue;
}

void Table::print(){
	for (int i = 0; i < tableLen; i++) {
		cout << pTable[i] << ", ";
	}
	cout << endl;
}

Table Table::operator+(Table &other){
	Table tableRes;
	tableRes.setName(*this->name + *other.name);
	tableRes.setNewSize(this->getSize() + other.getSize());
	for (int i = 0; i < this->getSize(); i++) {
		tableRes.pTable[i] = this->pTable[i];
	}
	for (int j = 0; j < other.getSize(); j++) {
		tableRes.pTable[this->getSize() + j] = other.pTable[j];
	}

	return move(tableRes);
	
}

/*
Table & Table::operator=(Table & other){
	this->setName(*other.name);
	this->setNewSize(other.tableLen); // w srodku tej funckji zwalnia te stara tablice, wiec git
	this->tableLen = other.tableLen;
	for (int i = 0; i < (this->tableLen); i++) {
		this->pTable[i] = other.pTable[i];
	}
	return *this;
}



*/
Table& Table::operator=(Table&& other) {
	cout << " op move =  ";
	
	this->moveHelper(other);

	return (*this);
}

void Table::operator=(const Table & other){
	cout << " op = ";
	this->setName(*other.name);
	this->setNewSize(other.tableLen); // w srodku tej funckji zwalnia te stara tablice, wiec git
	this->tableLen = other.tableLen;
	for (int i = 0; i < (this->tableLen); i++) {
		this->pTable[i] = other.pTable[i];
	}

}





Table Table::operator-(Table & other){
	
	int newSize = 0;
	int* newTable = new int [(this->tableLen)];
	for (int i = 0; i < (this->tableLen); i++) {
			if (!other.isContain(this->pTable[i])) {
				newTable[newSize] = this->pTable[i];
				newSize++;
			}
	}
	Table tableRes ("sub", newSize);
	for (int j = 0; j < newSize; j++) {
		tableRes.pTable[j] = newTable[j];
	}
	delete[] newTable;
	return move(tableRes);
}

bool Table::isContain(int number){
	for (int i = 0; i < tableLen; i++) {
		if (pTable[i] == number) return true;
	}
	return false;
}

void Table::moveHelper(Table & other)
{
	if (name != NULL) delete name;
	if (pTable != NULL) delete[] pTable;

	this->name = other.name;
	this->tableLen = other.tableLen;
	this->pTable = other.pTable;

	other.name = NULL;
	other.pTable = NULL;
}

/*
Table Table::operator/(Table & other)
{ 
	int newSize = 0;
	int* newTable = new int[(this->tableLen)];

	for (int i = 0; i < (this->tableLen); i++) {
		if (other.isContain(this->pTable[i])) {
			newTable[newSize] = this->pTable[i];
			newSize++;
		}
	}
	Table tableRes ("div", newSize);
	for (int j = 0; j < newSize; j++) {
		tableRes.pTable[j] = newTable[j];
	}
	delete[] newTable;
	return move(tableRes);
}
*/
