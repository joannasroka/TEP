#include "pch.h"
#include "MscnProblem.h"
#include <iostream>

MscnProblem::MscnProblem(int deliverersNumber, int factoriesNumber, int magazinesNumber, int shopsNumber)
{
	this->deliverersNumber = deliverersNumber;
	this->factoriesNumber = factoriesNumber;
	this->magazinesNumber = magazinesNumber;
	this->shopsNumber = shopsNumber;
}

MscnProblem::MscnProblem(
	Table* sd, Table* sf, Table* sm, Table* ss, 
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

	double* xd = solution; // wskazuje na pocz¹tek solution, bo tam jest xd
	double* xf = solution + (deliverersNumber * factoriesNumber);  // wskazuje w solution na miejsce za xd
	double* xm = xf + (factoriesNumber * magazinesNumber); // itd
	
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

	delete xdMin;
	delete xdMax;
	delete xfMin;
	delete xfMax;
	delete xmMin;
	delete xmMax;

	// usuwanie modyfikacji

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
void MscnProblem::generateInstance(int instanceSeed)
{
	// wypelnienie mocy produkcyjnych
	RandomDouble randomDouble(instanceSeed, S_MIN, S_MAX);

	sd = new Table(deliverersNumber);
	sf = new Table(factoriesNumber);
	sm = new Table(magazinesNumber);
	ss = new Table(shopsNumber);

	randomDouble.fillTable(sd);
	randomDouble.fillTable(sf);
	randomDouble.fillTable(sm);
	randomDouble.fillTable(ss);

	// wypelnienie kosztow korzystania
	randomDouble.setMinDouble(U_MIN);
	randomDouble.setMaxDouble(U_MAX);

	 ud = new Table(deliverersNumber);
	 uf = new Table (factoriesNumber);
	 um = new Table(magazinesNumber);

	randomDouble.fillTable(ud);
	randomDouble.fillTable(uf);
	randomDouble.fillTable(um);

	// wypelnienie przychodow
	randomDouble.setMinDouble(P_MIN);
	randomDouble.setMaxDouble(P_MAX);

	ps = new Table(shopsNumber);

	randomDouble.fillTable(ps);
	
	// wypelnienie kosztow transportow
	randomDouble.setMinDouble(C_MIN);
	randomDouble.setMaxDouble(C_MAX);

	cd = new Matrix(deliverersNumber, factoriesNumber);
	cf = new Matrix(factoriesNumber, magazinesNumber);
	cm = new Matrix(magazinesNumber, shopsNumber);

	randomDouble.fillMatrix(cd);
	randomDouble.fillMatrix(cf);
	randomDouble.fillMatrix(cm);

	// wypelnienie x_minów

	xdMin = new Matrix(deliverersNumber, factoriesNumber, 0.0);
	xfMin = new Matrix(factoriesNumber, magazinesNumber, 0.0);
	xmMin = new Matrix(magazinesNumber, shopsNumber, 0.0);
	
	// wypelnienie x_maxow

	xdMax = new Matrix(deliverersNumber, factoriesNumber);
	xfMax = new Matrix(factoriesNumber, magazinesNumber);
	xmMax = new Matrix(magazinesNumber, shopsNumber);

	fillXMax(xdMax, sd, deliverersNumber, factoriesNumber);
	fillXMax(xfMax, sf, factoriesNumber, magazinesNumber);

	fillxmMax(xmMax, sm, ss);





}
void MscnProblem::fillXMax(Matrix* xMax, Table *strenght, int fromSize, int toSize)
{
	double* currentStrength = new double(0.0);
	for (int i = 0; i < fromSize; i++) {
		strenght->getValueAt(currentStrength, i); // co currentStrenght zapisuje to co jest pod strenght[i]
		*currentStrength = ((*currentStrength) * 1.5) / toSize;

		for (int j = 0; j < toSize; j++) {
			xMax->setValueAt(*currentStrength, i, j);
		}
	}
	delete currentStrength;
}

// dla xm max jest inaczej, bo musze sprawdzac ograniczenia magazynowe oraz sklepowe
void MscnProblem::fillxmMax(Matrix* xmMax, Table* sm, Table* ss) {

	double* currentMagazineStrength = new double(0.0);
	double* currentShopStrength = new double(0.0);
	double* currentStrength = new double(0.0);

	for (int i = 0; i < magazinesNumber; i++) {
		sm->getValueAt(currentMagazineStrength, i); //  zapisuje to co jest pod sm[i]

		for (int j = 0; j < shopsNumber; j++) {
			ss->getValueAt(currentShopStrength, j); // zapisuje to co jest pod ss[j]

			*currentStrength = *currentMagazineStrength > *currentShopStrength ? 
				(*currentShopStrength*1.5 / magazinesNumber) : (*currentMagazineStrength*1.5 / shopsNumber);

			xmMax->setValueAt(*currentStrength, i, j);
		}
	}
	delete currentMagazineStrength;
	delete currentShopStrength;
	delete currentStrength;
}


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
