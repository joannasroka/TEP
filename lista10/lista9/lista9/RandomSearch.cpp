#include "pch.h"
#include "RandomSearch.h"
#include "MscnProblem.h"

/*
RandomSearch::RandomSearch(
	Matrix * xdMin, Matrix * xdMax,
	Matrix * xfMin, Matrix * xfMax,
	Matrix * xmMin, Matrix * xmMax,
	int deliverersNumber, int factoriesNumber, int magazinesNumber, int shopsNumber)
{

	this->xdMin = xdMin;
	this->xdMax = xdMax;
	this->xfMin = xfMin;
	this->xfMax = xfMax;
	this->xmMin = xmMin;
	this->xmMax = xmMax;

	this->deliverersNumber = deliverersNumber;
	this->factoriesNumber = factoriesNumber;
	this->magazinesNumber = magazinesNumber;
	this->shopsNumber = shopsNumber;

}
*/

RandomSearch::RandomSearch(MscnProblem * mscnProblem, int seed)
{
	this->xdMin = mscnProblem->xdMin;
	this->xdMax = mscnProblem->xdMax;

	this->xfMin = mscnProblem->xfMin;
	this->xfMax = mscnProblem->xfMax;

	this->xmMin = mscnProblem->xmMin;
	this->xmMax = mscnProblem->xmMax;

	this->deliverersNumber = mscnProblem->deliverersNumber;
	this->factoriesNumber = mscnProblem->factoriesNumber;
	this->magazinesNumber = mscnProblem->magazinesNumber;
	this->shopsNumber = mscnProblem->shopsNumber;

	randomDouble.setSeed(seed); // ustawiam seeda 
	randomInt.setSeed(seed);
}

double * RandomSearch::createSolution(MscnProblem* mscnProblem, double* bestQuality)
{
	int size = (deliverersNumber*factoriesNumber) + (factoriesNumber*magazinesNumber) + (magazinesNumber*shopsNumber);
	int* index = new int(0);
	double* solution = new double[size];
	double* changedSolution = new double[size];
	double* bestSolution = new double[size];

	bool *isCorrect = new bool(false);

	double currentQuality;
	 *bestQuality = -100000000;

	for (int i = 0; i < 100; i++) {
		*index = 0;

		fillXArray( solution, index, xdMin, xdMax, deliverersNumber, factoriesNumber); // xd
		fillXArray( solution, index, xfMin, xfMax, factoriesNumber, magazinesNumber); // xf
		fillXArray( solution, index, xmMin, xmMax, magazinesNumber, shopsNumber); // xm

		changedSolution = swapAllSolution(mscnProblem, bestSolution, solution, size);
		for (int j = 0; j < size; j++) {
			bestSolution[j] = changedSolution[j];
		}
		//currentQuality = mscnProblem->getQuality(solution, size, isCorrect);
		

		/*
		if (currentQuality > *bestQuality && *isCorrect == true ) {
			*bestQuality = currentQuality;
			for (int j = 0; j < size; j++) {
				bestSolution[j] = solution[j];
			}
		}
		*/

	}
	delete index;
	delete isCorrect;
	return bestSolution;
}

double * RandomSearch::swapHalfBestSolution(MscnProblem * mscnProblem, double * bestSolution,  int solutionSize)
{
	int* usedIndex = new int [solutionSize/2]; // tu beda juz zmienione indeksy
	int amountOfRandomIndexes = 0;

	for (int i = 0; i < solutionSize / 2; i++) {
		usedIndex[i] = -1;
	}
	randomInt.setMaxInt(solutionSize - 1);
	randomInt.setMinInt(0);
	
	int randomIndex = randomInt.getRandomInt();

	while (amountOfRandomIndexes != solutionSize / 2) {

		while (indexIsContain(usedIndex, randomIndex, solutionSize / 2))
		{
			randomIndex = randomInt.getRandomInt();
		}
		usedIndex[amountOfRandomIndexes] = randomIndex;
		amountOfRandomIndexes++;

		double* min = new double(0.0); // tu zapiszemy zakres wylosowanego pola z solution
		double* max = new double(0.0);

		mscnProblem->getMinMax(min, max, randomIndex); // tu dostajemy zakres dla naszego wylosowanego indexu

		randomDouble.setMinDouble(*min); // ale to musi tutaj byc
		randomDouble.setMaxDouble(*max);

		bestSolution[randomIndex] = randomDouble.getRandomDouble();
	}
	return bestSolution;
	
}

double * RandomSearch::swapAllSolution(MscnProblem * mscnProblem, double * bestSolution, double * actSolution, int solutionSize)
{
	int* usedIndex = new int[solutionSize]; // tu beda juz zmienione indeksy
	int amountOfRandomIndexes = 0;			// ilosc zmienionych w actSolution indeksow
	bool* isCorrect = new bool(false);

	for (int i = 0; i < solutionSize; i++) {
		usedIndex[i] = -1;
	}
	randomInt.setMaxInt(solutionSize - 1); // randomInt bedzie losowac indeksy
	randomInt.setMinInt(0);

	int randomIndex = randomInt.getRandomInt();
	double currentQuality;

	while (amountOfRandomIndexes != solutionSize) {

		while (indexIsContain(usedIndex, randomIndex, solutionSize))
		{
			randomIndex = randomInt.getRandomInt();
		}
		usedIndex[amountOfRandomIndexes] = randomIndex;
		amountOfRandomIndexes++;

		//double* min = new double(0.0); // tu zapiszemy zakres wylosowanego pola z solution
		//double* max = new double(0.0);

		//mscnProblem->getMinMax(min, max, randomIndex); // tu dostajemy zakres dla naszego wylosowanego indexu

		//randomDouble.setMinDouble(*min); 
		//randomDouble.setMaxDouble(*max);

		actSolution[randomIndex] = bestSolution[randomIndex];

		currentQuality = mscnProblem->getQuality(actSolution, solutionSize, isCorrect);

		if (( currentQuality > mscnProblem->getQuality(bestSolution, solutionSize, isCorrect))) {
			return actSolution;
		}
	}
	delete isCorrect;
	delete[] usedIndex;

	return bestSolution;
}

void RandomSearch::fillXArray(double* solution, int* currentIndex,
	Matrix * xMin, Matrix * xMax,
	int fromSize, int toSize)
{
	double* currentMax = new double(0.0);
	double* currentMin = new double(0.0);

	for (int i = 0; i < fromSize; i++) {
		for (int j = 0; j < toSize; j++) {
			xMax->getValueAt(currentMax, i, j);
			xMin->getValueAt(currentMin, i, j);

			randomDouble.setMinDouble(*currentMin); // ale to musi tutaj byc
			randomDouble.setMaxDouble(*currentMax);

			solution[*currentIndex] = randomDouble.getRandomDouble();
			(*currentIndex)++;
		}
	}

	delete currentMax;
	delete currentMin;

}

bool RandomSearch::indexIsContain(int * usedIndex, int index, int size)
{
	for (int i = 0; i < size; i++) {
		if (usedIndex[i] == index) return true;
	}
	return false;
}


RandomSearch::~RandomSearch()
{
}
