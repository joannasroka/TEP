#pragma once
#include"Table.h"
#include"Matrix.h"
#include "RandomDouble.h"
#include "RandomInt.h"

#define C_MIN 3
#define C_MAX 10

#define S_MIN 1
#define S_MAX 7

#define U_MIN 5
#define U_MAX 15

#define P_MIN 42
#define P_MAX 90

class MscnProblem
{
public:


	MscnProblem(Table* sd, Table* sf, Table* sm, Table* ss,
		Table* ud, Table* uf, Table* um,
		Table* ps, 
		Matrix* cd, Matrix* cf, Matrix* cm,
	Matrix* xdMin,
	Matrix* xdMax,
	Matrix* xfMin,
	Matrix* xfMax,
	Matrix* xmMin,
	Matrix* xmMax

	
		/*
		,double* dfMin,
	double* dfMax,

	double* fmMin, // fabryki - magazyny
	double* fmMax,

	double* msMin, // magazyny - sklepy
	double* msMax
	*/
		);

	MscnProblem(int deliverersNumber, int factoriesNumber, int magazinesNumber, int shopsNumber);

	double getQuality(double* solution, int size, bool* isCorrect);

	bool constraintsSatisfied(double* solution);

	bool getMinMax(double* min, double* max, int index);

	void generateInstance(int instanceSeed);

	void fillXMax(Matrix* xMax, Table* strenght, int fromSize, int toSize); // moce produckyjne, pojemnosc sklepow, etc 
	// from: np. od dostawcow; to: do fabryk

	void fillxmMax(Matrix* xmMax, Table* sm, Table* ss);

	~MscnProblem();

	//void showModifi();

	int deliverersNumber;
	int factoriesNumber;
	int magazinesNumber;
	int shopsNumber;

	bool changeDeliverersNumber(int newNumber);
	bool changeFactoriesNumber(int newNumber);
	bool changeMagazinesNumber(int newNumber);
	bool changeShopsNumber(int newNumber);


	Table* sd; // moce produkcyjne dostawcow
	Table* sf; // moce produkcyjne fabryk
	Table* sm; // pojemnosci magazynow
	Table* ss; // zapotrzebowanie rynkowe sklepow

	Table* ud; // koszt sta�ych um�w dostawc�w
	Table* uf; // koszt sta�ych um�w fabryk
	Table* um; // koszt sta�ych um�w magazyn�w


	Matrix* cd; // koszt dostawca-fabryka
	Matrix* cf; // koszt fabryka-magazyn
	Matrix* cm; // koszt magazyn-sklep

	Table* ps; // przychody sklep�w

	Matrix* xdMin;
	Matrix* xdMax;
	Matrix* xfMin;
	Matrix* xfMax;
	Matrix* xmMin;
	Matrix* xmMax;


	/*
	double* dfMin; // dostawca - fabryka
	double* dfMax;

	double* fmMin; // fabryki - magazyny
	double* fmMax;

	double* msMin; // magazyny - sklepy
	double* msMax;

	 void setMinMaxMod(double* dfMin, double* dfMax, double* fmMin, double* fmMax, double* msMin, double* msMax);
	 */
	
	

private:
	double getCostT(double* xd, double* xf, double* xm);
	double getCostU(double* xd, double* xf, double* xm);

	bool constraintProduction(double* x_, Table* s_, int xSize, int ySize);
	bool constraintShops(double* xm, Table* ss, int xSize, int ySize);
	bool constraintInOut(double* xIn, double* xOut, int xSize, int ySize, int zSize);


	
};
