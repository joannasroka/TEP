#include "pch.h"
#include "RandomInt.h"
#define SEED 3
#define MIN 0
#define MAX 10


RandomInt::RandomInt()
{

	seed = SEED;
	minInt = MIN;
	maxInt = MAX;

	this->gen = mt19937(seed);
	this->randomInt = uniform_int_distribution<>(minInt, maxInt);
}

RandomInt::RandomInt(int seed, int min, int max)
{

	this->seed = seed;
	if (min > max) {
		this->minInt = max;
		this->maxInt = min;
	}
	else {
		this->minInt = min;
		this->maxInt = max;
	}
	this->gen = mt19937(seed);
	this->randomInt = uniform_int_distribution<>(minInt, maxInt);
}

RandomInt::~RandomInt()
{
}

bool RandomInt::setSeed(int seed)
{
	if (seed <= 0) return false;
	this->seed = seed;

	this->gen = mt19937(seed);
	return true;
}



bool RandomInt::setMinInt(int min)
{
	if (min <= maxInt) minInt = min;
	else return false;

	randomInt = uniform_int_distribution<>(minInt, maxInt);
	return true;
}

bool RandomInt::setMaxInt(int max)
{
	if (max >= minInt) maxInt = max;
	else return false;

	randomInt = uniform_int_distribution<>(minInt, maxInt);
	return true;
}


int RandomInt::getRandomInt()
{
	return randomInt(gen);
}

void RandomInt::fillTable(Table * table)
{
	for (int i = 0; i < table->getSize(); i++) {
		table->setValueAt(this->getRandomInt(), i);
	}
}

void RandomInt::fillMatrix(Matrix * matrix)
{
	for (int i = 0; i < matrix->getSizeX(); i++) {
		for (int j = 0; j < matrix->getSizeY(); j++) {
			matrix->setValueAt(this->getRandomInt(), i, j);
		}
	}
}
