#include "pch.h"
#include "RandomDouble.h"

#define SEED 3
#define MIN 0
#define MAX 10



RandomDouble::RandomDouble()
{
	seed = SEED;
	minDouble = MIN;
	maxDouble = MAX;

	this->gen = mt19937(seed);
	this->randomDouble = uniform_real_distribution<>(minDouble, maxDouble);
}

RandomDouble::RandomDouble(int seed, double min, double max)
{
	this->seed = seed;

	if (min > max) {
		this->minDouble = max;
		this->maxDouble = min;
	}
	else {
		this->minDouble = min;
		this->maxDouble = max;
	}


	this->gen = mt19937(seed);
	this->randomDouble = uniform_real_distribution<>(minDouble, maxDouble);
}

RandomDouble::~RandomDouble()
{
}

bool RandomDouble::setSeed(int seed)
{
	if (seed <= 0) return false;
	this->seed = seed;

	this->gen = mt19937(seed);
	return true;
}

bool RandomDouble::setMinDouble(double min)
{
	if (min <= maxDouble) minDouble = min;
	else return false;

	randomDouble = uniform_real_distribution<>(minDouble, maxDouble);
	return true;
}

bool RandomDouble::setMaxDouble(double max)
{
	if (max >= minDouble) maxDouble = max;
	else return false;

	randomDouble = uniform_real_distribution<>(minDouble, maxDouble);
	return true;
}

double RandomDouble::getRandomDouble()
{
	return randomDouble(gen);
}
void RandomDouble::fillTable(Table * table)
{
	for (int i = 0; i < table->getSize(); i++) {
		table->setValueAt(this->getRandomDouble(), i);
	}
}
void RandomDouble::fillMatrix(Matrix * matrix)
{
	for (int i = 0; i < matrix->getSizeX(); i++) {
		for (int j = 0; j < matrix->getSizeY(); j++) {
			matrix->setValueAt(this->getRandomDouble(), i, j);
		}
	}
}

