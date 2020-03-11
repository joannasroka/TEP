#pragma once
#include <random>
#include <iostream>
#include "Table.h"
#include "Matrix.h"

using namespace std;

class RandomDouble
{
public:
	RandomDouble();
	RandomDouble(int seed, double min, double max);
	~RandomDouble();

	bool setSeed(int seed);

	bool setMinDouble(double min);
	bool setMaxDouble(double max);

	double getRandomDouble();

	void fillTable(Table* table);
	void fillMatrix(Matrix* matrix);

private:
	int seed;
	mt19937 gen;

	double minDouble;
	double maxDouble;

	uniform_real_distribution<> randomDouble;
};

