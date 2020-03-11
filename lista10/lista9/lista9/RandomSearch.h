#pragma once
#include "Matrix.h"
#include "RandomDouble.h"
#include "RandomInt.h"
#include "MscnProblem.h"

using namespace std;

class RandomSearch
{
public:
	/*
	RandomSearch(Matrix* xdMin,
		Matrix* xdMax,
		Matrix* xfMin,
		Matrix* xfMax,
		Matrix* xmMin,
		Matrix* xmMax,
		int deliverersNumber, int factoriesNumber, int magazinesNumber, int shopsNumber);
		*/

	RandomSearch(MscnProblem* mscnProblem, int seed);

	double* createSolution(MscnProblem* mscnProblem, double* bestQuality);
	double* swapHalfBestSolution(MscnProblem* mscnProblem, double* bestSolution, int solutionSize);
	double* swapAllSolution(MscnProblem* mscnProblem, double*bestSolution, double* actSolution, int solutionSize);
	
	~RandomSearch();

private:
	void fillXArray(double* solution, int* currentIndex, 
		Matrix* xMin, Matrix* xMax,
		int fromSize, int toSize);

	bool indexIsContain(int* usedIndex, int index, int size);

	RandomDouble randomDouble;
	RandomInt randomInt;
	
	Matrix* xdMin;
	Matrix* xdMax;
	Matrix* xfMin;
	Matrix* xfMax;
	Matrix* xmMin;
	Matrix* xmMax;

	int deliverersNumber;
	int factoriesNumber; 
	int magazinesNumber;
	int shopsNumber;

};

