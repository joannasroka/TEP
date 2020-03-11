#include "pch.h"
#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix()
{
	//cout << "konstruktor domyslny " << endl;
	pMatrix = new double*[DEF_SIZEX];
	for (int i = 0; i < DEF_SIZEX; i++) {
		pMatrix[i] = new double[DEF_SIZEY];
	}
	sizeX = DEF_SIZEX;
	sizeY = DEF_SIZEY;
}


Matrix::Matrix(double ** pMatrix, int newSizeX, int newSizeY)
{
	sizeX = newSizeX;
	sizeY = newSizeY;

	this->pMatrix = pMatrix;
}

Matrix::Matrix(int newSizeX, int newSizeY)
{
	if (newSizeX <= 0) sizeX = DEF_SIZEX;
	else sizeX = newSizeX;
	if (newSizeY <= 0) sizeY = DEF_SIZEY;
	else sizeY = newSizeY;

	//cout << "konstruktor z parametrem: " << sizeX << ", " << sizeY << endl;

	pMatrix = new double*[sizeX];
	for (int i = 0; i < sizeX; i++) {
		pMatrix[i] = new double[sizeY];
	}

}

Matrix::Matrix(const Matrix & other)
{
	//cout << "konstruktor kopiujacy " << endl;
	copy(other);
}

Matrix::Matrix(Matrix && other)
{
	//cout << "konstuktor przenoszacy " << endl;
	moveHelper(other);
}

Matrix::Matrix(string fileLine, int sizeX, int sizeY)
{
	// usuwanie bialych znakow
	fileLine.erase(remove_if(fileLine.begin(), fileLine.end(), ::isspace), fileLine.end());

	string delimiter = ";";
	this->sizeX = sizeX;
	this->sizeY = sizeY;

	pMatrix = new double*[sizeX];
	for (int i = 0; i < sizeX; i++) {
		pMatrix[i] = new double[sizeY];
	}

	int indexX = 0;
	int indexY = 0;

	size_t pos = 0;
	string token;
	while ((pos = fileLine.find(delimiter)) != std::string::npos) {
		if (pos == 0) fileLine.erase(0, delimiter.length());
		else {
			token = fileLine.substr(0, pos);
			pMatrix[indexX][indexY] = stod(token);

			indexY++;
			if (indexY == sizeY) {
				indexY = 0;
				indexX++;
			}
			fileLine.erase(0, pos + delimiter.length());
		}
		/*
		token = fileLine.substr(0, pos);

		pMatrix[indexX][indexY] = stod(token);

		indexY++;
		if (indexY == sizeY ) {
			indexY = 0;
			indexX++;
		}
	
		fileLine.erase(0, pos + delimiter.length());
		*/
	}
}

Matrix::Matrix(int newSizeX, int newSizeY, double oneValue)
{
	if (newSizeX <= 0) sizeX = DEF_SIZEX;
	else sizeX = newSizeX;
	if (newSizeY <= 0) sizeY = DEF_SIZEY;
	else sizeY = newSizeY;

	//cout << "konstruktor z parametrem: " << sizeX << ", " << sizeY << endl;

	pMatrix = new double*[sizeX];
	for (int i = 0; i < sizeX; i++) {
		pMatrix[i] = new double[sizeY];
		for (int j = 0; j < sizeY; j++) {
			pMatrix[i][j] = oneValue;
		}
	}
}


Matrix & Matrix::operator=(const Matrix & other)
{
	//cout << "op= " << endl;
	copy(other);
	return(*this);
}

Matrix & Matrix::operator=(Matrix && other)
{
	//cout << "op move= " << endl;
	this->moveHelper(other);
	return (*this);
}

double Matrix::multiply(double * table)
{
	double result = 0.0;
	int tableIndex = 0;
	for (int x = 0; x < sizeX; x++) {
		for (int y = 0; y < sizeY; y++) {
			result += pMatrix[x][y] * table[tableIndex];
			tableIndex++;
		}
	}
	return result;
}

bool Matrix::setValueAt(double value, int x, int y)
{
	if (x < 0 || x >= sizeX || y < 0 || y >= sizeY) return false;
	pMatrix[x][y] = value;
	return true;
}

bool Matrix::getValueAt(double* value, int x, int y)
{
	if (x < 0 || y < 0 || x >= sizeX || y >= sizeY) return false;
	*value = pMatrix[x][y];
	return true;
}

string Matrix::toString()
{
	string result = "";
	for (int x = 0; x < sizeX; x++) {
		for (int y = 0; y < sizeY; y++) {
			result += to_string(pMatrix[x][y]);
			result += "  ;; ; ";

		}
	}
	return result;
}




bool Matrix::setSize(int newSizeX, int newSizeY)
{
	if (newSizeX < 0 || newSizeY < 0) return false;
	if (newSizeX == 0) sizeX = 1;
	if (newSizeY == 0) sizeY = 1;

	double ** newpMatrix = new double*[sizeX];
	for (int i = 0; i < sizeX; i++)
	{
		newpMatrix[i] = new double[sizeY];
	}

	if (pMatrix != NULL) {
		for (int i = 0; i < sizeX; i++) {
			delete[] pMatrix[i];
		}
		delete[] pMatrix;
	}
	pMatrix = newpMatrix;
	return true;


}

int Matrix::getSizeX()
{
	return sizeX;
}

int Matrix::getSizeY()
{
	return sizeY;
}

Matrix::~Matrix()
{
	//cout << " destruktor " << endl;
	if (pMatrix != NULL) {
		for (int i = 0; i < sizeX; i++) {
			delete[] pMatrix[i];
		}
		delete[] pMatrix;
	}
}

void Matrix::copy(const Matrix & other)
{
	if (pMatrix != NULL) {
		for (int i = 0; i < sizeX; i++) {
			delete[] pMatrix[i];
		}
		delete[] pMatrix;
	}
	//cout << "kopiowanie " << endl;
	sizeX = other.sizeX;
	sizeY = other.sizeY;

	pMatrix = new double*[other.sizeX];
	for (int i = 0; i < sizeX; i++) {
		pMatrix[i] = new double[sizeY];
		for (int j = 0; j < sizeY; j++) {
			pMatrix[i][j] = other.pMatrix[i][j];
		}
	}


}

void Matrix::moveHelper(Matrix & other)
{
	if (pMatrix != NULL) {
		for (int i = 0; i < sizeX; i++) {
			delete[] pMatrix[i];
		}
		delete[] pMatrix;
	}

	pMatrix = other.pMatrix;
	sizeX = other.sizeX;
	sizeY = other.sizeY;

	other.pMatrix = NULL;

	//cout << "przenoszenie " << endl;

}
