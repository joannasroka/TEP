#include "pch.h"
#include <iostream>
#include "TabDouble.h"

using namespace std;


TabDouble::TabDouble()
{
	cout << "konstruktor ";
	pDoub = new double(DEF_DOUBLE);
}

TabDouble::TabDouble(const TabDouble & other)
{
	cout << " konstruktor kopiujacy ";
	pDoub = new double(*other.pDoub);
}

TabDouble::TabDouble(TabDouble && other)
{
	cout << " konstruktor przenoszacy ";
	pDoub = other.pDoub;
	other.pDoub = NULL;
}

TabDouble & TabDouble::operator=(const TabDouble & other)
{
	cout << " = kopiujace ";
	if(other.pDoub != NULL) *pDoub = *(other.pDoub);
	return (*this);
}

TabDouble & TabDouble::operator=(TabDouble && other)
{
	cout << " = przenoszace ";
	if (pDoub != NULL) delete pDoub;
	if (other.pDoub != NULL) pDoub = other.pDoub;
	other.pDoub = NULL;
	return (*this);
}

TabDouble::~TabDouble()
{
	cout << " destruktor ";
	if (pDoub != NULL) delete pDoub;
}
