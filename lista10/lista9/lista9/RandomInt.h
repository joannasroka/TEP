#pragma once
#include <random>
#include <iostream>
#include "Table.h"
#include "Matrix.h"

using namespace std;

class RandomInt
{
public:
	RandomInt();
	RandomInt(int seed, int min, int max);
	~RandomInt();

	bool setSeed(int seed);

	bool setMinInt(int min);
	bool setMaxInt(int max);

	int getRandomInt();

	void fillTable(Table* table);
	void fillMatrix(Matrix* matrix);

private:
	int seed;
	mt19937 gen;


	int minInt;
	int maxInt;

	uniform_int_distribution<> randomInt;
	
};

