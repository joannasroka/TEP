#pragma once
#pragma once
#define DEF_SIZEX 2
#define DEF_SIZEY 3
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>



using namespace std;
class Matrix
{
public:
public:
	Matrix();
	Matrix(double** pMatrix, int newSizeX, int newSizeY);
	Matrix(int newSizeX, int newSizeY);
	Matrix(const Matrix& other);
	Matrix(Matrix&& other);
	Matrix(string fileLine, int sizeX, int sizeY);
	Matrix(int newSizeX, int newSizeY, double oneValue);

	Matrix& operator=(const Matrix& other); // moze tu byc Tab& lub void
	Matrix& operator=(Matrix&& other); // Tab& lub void

	double multiply(double* table);

	bool setValueAt(double value, int x, int y);
	bool getValueAt(double* value, int x, int y);

	string toString();

	
	bool setSize(int newSizeX, int newSizeY);

	int getSizeX();
	int getSizeY();

	~Matrix();


private:
	void copy(const Matrix& other);
	void moveHelper(Matrix& other);

	double **pMatrix;
	int sizeX;
	int sizeY;
};

