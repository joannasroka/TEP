#pragma once
#include"Table.h"
#include"Matrix.h"

class MscnProblem
{
public:
	MscnProblem();
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

	double getQuality(double* solution, int size, bool* isCorrect);

	bool constraintsSatisfied(double* solution);

	bool getMinMax(double* min, double* max, int index);

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

	Table* ud; // koszt sta³ych umów dostawców
	Table* uf; // koszt sta³ych umów fabryk
	Table* um; // koszt sta³ych umów magazynów


	Matrix* cd; // koszt dostawca-fabryka
	Matrix* cf; // koszt fabryka-magazyn
	Matrix* cm; // koszt magazyn-sklep

	Table* ps; // przychody sklepów

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
