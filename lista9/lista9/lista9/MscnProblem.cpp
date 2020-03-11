#include "pch.h"
#include "MscnProblem.h"
#include <iostream>

MscnProblem::MscnProblem()
{
}

MscnProblem::MscnProblem(Table* sd,
	Table* sf, Table* sm, Table* ss, Table* ud, Table* uf, Table* um, Table* ps, Matrix* cd, Matrix* cf, Matrix* cm,
	Matrix* xdMin,
	Matrix* xdMax,
	Matrix* xfMin,
	Matrix* xfMax,
	Matrix* xmMin,
	Matrix* xmMax

	/*
	,double* dfMin,
	double* dfMax,

	double* fmMin, 
	double* fmMax,

	double* msMin, 
	double* msMax
	*/
	)

{
	this->sd = sd;
	this->sf = sf;
	this->sm = sm;
	this->ss = ss;

	this->cd = cd;
	this->cf = cf;
	this->cm = cm;

	this->ud = ud;
	this->uf = uf;
	this->um = um;

	this->ps = ps;

	this->xdMin = xdMin;
	this->xdMax = xdMax;
	this->xfMin = xfMin;
	this->xfMax = xfMax;
	this->xmMin = xmMin;
	this->xmMax = xmMax;
	

	deliverersNumber = ud->getSize();
	factoriesNumber = uf->getSize();
	magazinesNumber = um->getSize();
	shopsNumber = ps->getSize();

	/*
	this->dfMin = dfMin;
	this->dfMax = dfMax;

	this->fmMin = fmMin;
	this->fmMax = fmMax;


	this->msMin = msMin;
	this->msMax = msMax;
	*/
}

double MscnProblem::getQuality(double * solution, int size, bool* isCorrect)
{
	if (solution == NULL) *isCorrect = false;
	if (size != ((deliverersNumber*factoriesNumber) + (factoriesNumber*magazinesNumber) + (magazinesNumber*shopsNumber))) *isCorrect = false;

	double* xd = solution;
	double* xf = solution + (deliverersNumber * factoriesNumber);
	double* xm = xf + (factoriesNumber * magazinesNumber);
	
	*isCorrect = true;
	return ps->calculateProfit(xm, magazinesNumber) - getCostT(xd, xf, xm) - getCostU(xd, xf, xm);

}

bool MscnProblem::constraintsSatisfied(double * solution)
{
	double* xd = solution;
	double* xf = solution + (deliverersNumber * factoriesNumber);
	double* xm = xf + (factoriesNumber * magazinesNumber);

	return constraintProduction(xd, sd, deliverersNumber, factoriesNumber)
		&& constraintProduction(xf, sf, factoriesNumber, magazinesNumber)
		&& constraintProduction(xm, sm, magazinesNumber, shopsNumber)
		&& constraintShops(xm, ss, magazinesNumber, shopsNumber)
		&& constraintInOut(xd, xf, deliverersNumber, factoriesNumber, magazinesNumber)
		&& constraintInOut(xf, xm, factoriesNumber, magazinesNumber, shopsNumber);
}

bool MscnProblem::getMinMax(double * min, double * max, int index)
{
	int maxIndex = deliverersNumber * factoriesNumber
		+ factoriesNumber * magazinesNumber
		+ magazinesNumber * shopsNumber; // rozmiar solution

	if (index < 0 || index >= maxIndex) return false;
	
	int x, y;
	double* value = new double(0.0);

	if (index < deliverersNumber * factoriesNumber) {
		x = index / factoriesNumber;
		y = index % factoriesNumber;


		if (xdMin->getValueAt(value, x, y)) {
			
			*min = *value;
		
		}
		else {
			delete value;
			return false; }
		if (xdMax->getValueAt(value, x, y)) { 
			
			*max = *value;
			delete value;
		}
		else {
			delete value;
			return false; }

		return true;
	}
	else if (index < deliverersNumber * factoriesNumber + factoriesNumber * magazinesNumber) {
		index -= deliverersNumber * factoriesNumber;
		x = index / magazinesNumber;
		y = index % magazinesNumber;

		if (xfMin->getValueAt(value, x, y)) {
			
			*min = *value;
			
		}
		else {
			delete value;
			return false;
		}
		if (xfMax->getValueAt(value, x, y)) {
			
			*max = *value;
			delete value;
		}
		else {
			delete value;
			return false;
		}

		return true;
	
	}
	else {
		index -= deliverersNumber * factoriesNumber;
		index -= factoriesNumber * magazinesNumber;
		x = index / shopsNumber;
		y = index % shopsNumber;

		if (xmMin->getValueAt(value, x, y)) {
			
			*min = *value;
		
		}
		else {
			delete value;
			return false;
		}
		if (xmMax->getValueAt(value, x, y)) {
			
			*max = *value;
			delete value;
		}
		else {
			delete value;
			return false; }

		return true;
	}
	return false;
}


MscnProblem::~MscnProblem()
{

	delete sd; // moce produkcyjne dostawcow
	delete sf; // moce produkcyjne fabryk
	delete sm; // pojemnosci magazynow
	delete ss; // zapotrzebowanie rynkowe sklepow
	
	delete ud; // koszt sta³ych umów dostawców
	delete uf; // koszt sta³ych umów fabryk
	delete um; // koszt sta³ych umów magazynów


	delete cd; // koszt dostawca-fabryka
	delete cf; // koszt fabryka-magazyn
	delete cm; // koszt magazyn-sklep

	delete ps; // przychody sklepów

}

/*
void MscnProblem::showModifi()
{
	cout << "modyfikacja: ";
	cout << *dfMin << " " << *dfMax << endl;
	cout << *fmMin << " " << *fmMax << endl;
	cout << *msMin << " " << *msMax << endl;
}
*/
bool MscnProblem::changeDeliverersNumber(int newNumber)
{
	if (newNumber <= 0) return false;

	deliverersNumber = newNumber;
	if (!sd->setSize(newNumber)) return false;
	if (!ud->setSize(newNumber)) return false;

	if (!cd->setSize(newNumber, factoriesNumber)) return false;
	if (!xdMin->setSize(newNumber, factoriesNumber)) return false;
	if (!xdMax->setSize(newNumber, factoriesNumber)) return false;

	return true;
}

bool MscnProblem::changeFactoriesNumber(int newNumber)
{
	if (newNumber <= 0) return false;

	factoriesNumber = newNumber;
	if (!sf->setSize(newNumber)) return false;
	if (!uf->setSize(newNumber)) return false;

	if (!cf->setSize(newNumber, magazinesNumber)) return false;
	if (!xfMin->setSize(newNumber, magazinesNumber)) return false;
	if (!xfMax->setSize(newNumber, magazinesNumber)) return false;

	if (!cd->setSize(deliverersNumber, newNumber)) return false;
	if (!xdMin->setSize(deliverersNumber, newNumber)) return false;
	if (!xdMax->setSize(deliverersNumber, newNumber)) return false;

	return true;
}

bool MscnProblem::changeMagazinesNumber(int newNumber)
{
	if (newNumber <= 0) return false;

	magazinesNumber = newNumber;
	if (!sm->setSize(newNumber)) return false;
	if (!um->setSize(newNumber)) return false;

	if (!cm->setSize(newNumber, shopsNumber)) return false;
	if (!xmMin->setSize(newNumber, shopsNumber)) return false;
	if (!xmMax->setSize(newNumber, shopsNumber)) return false;

	if (!cf->setSize(factoriesNumber, newNumber)) return false;
	if (!xfMin->setSize(factoriesNumber, newNumber)) return false;
	if (!xfMax->setSize(factoriesNumber, newNumber)) return false;


	return true;
}

bool MscnProblem::changeShopsNumber(int newNumber)
{
	if (newNumber <= 0) return false;

	shopsNumber = newNumber;
	if (!ss->setSize(newNumber)) return false;
	if (!ps->setSize(newNumber)) return false;

	if (!cm->setSize(magazinesNumber, newNumber)) return false;
	if (!xmMin->setSize(magazinesNumber, newNumber)) return false;
	if (!xmMax->setSize(magazinesNumber, newNumber)) return false;

	return true;
}

/*
void MscnProblem::setMinMaxMod(double * dfMin, double * dfMax, double * fmMin, double * fmMax, double * msMin, double * msMax)
{
	this->dfMin = dfMin;
	this->dfMax = dfMax;

	this->fmMin = fmMin;
	this->fmMax = fmMax;

	this->msMin = msMin;
	this->msMax = msMax;
}
*/
double MscnProblem::getCostT(double* xd, double* xf, double* xm)
{
	return cd->multiply(xd) + cf->multiply(xf) + cm->multiply(xm);
}

double MscnProblem::getCostU(double * xd, double * xf, double * xm)
{
	return ud->getCostU(xd, factoriesNumber) + uf->getCostU(xf, magazinesNumber) + um->getCostU(xm, shopsNumber);
}

bool MscnProblem::constraintProduction(double * x_, Table* s_, int xSize, int ySize)
{
	int index = 0;
	double result = 0.0;
	double* valueAt = NULL;

	for (int x = 0; x < xSize; x++) {
		result = 0.0;
		for (int y = 0; y < ySize; y++) {
			result += x_[index];
			index++;
		}

		s_->getValueAt(valueAt, x);
		if (result > *valueAt) return false;
		
	}
	delete valueAt;
	return true;
}

bool MscnProblem::constraintShops(double * xm, Table * ss, int xSize, int ySize)
{


	double result = 0.0;
	double* valueAt = NULL;

	for (int y = 0; y < ySize; y++) {
		result = 0.0;
		for (int x = 0; x < xSize; x++) {
			result += xm[y + ySize * x];

		}

		ss->getValueAt(valueAt, y);
		if (result > *valueAt) return false;

	}
	delete valueAt;
	return true;
}

bool MscnProblem::constraintInOut(double * xIn, double * xOut, int xSize, int ySize, int zSize)
{
	double sumIn = 0.0;
	double sumOut = 0.0;

	int indexOut = 0;
	

	for (int y = 0; y < ySize; y++) {
		for (int x = 0; x < xSize; x++) {
			sumIn += xIn[y + x * ySize];
		}
		for (int z = 0; z < zSize; z++) {
			sumOut += xOut[indexOut];
			indexOut++;
		}
		if (sumIn < sumOut) return false;

		sumIn = 0.0;
		sumOut = 0.0;
	}
	return true;
}
