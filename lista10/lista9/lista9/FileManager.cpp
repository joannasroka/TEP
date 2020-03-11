#include "pch.h"
#include "FileManager.h"
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable:4996)
#include <regex>



FileManager::FileManager()
{
}

bool FileManager::save(MscnProblem * mscnProblem)
{
	if (file == NULL) return false;

	fputs(to_string(mscnProblem->deliverersNumber).c_str(), file);
	fputs(string("\n").c_str(), file);
	fputs(to_string(mscnProblem->factoriesNumber).c_str(), file);
	fputs(string("\n").c_str(), file);
	fputs(to_string(mscnProblem->magazinesNumber).c_str(), file);
	fputs(string("\n").c_str(), file);
	fputs(to_string(mscnProblem->shopsNumber).c_str(), file);
	fputs(string("\n").c_str(), file);

	//fputs(string("\n").c_str(), file);
	
	fputs(mscnProblem->sd->toString().c_str(), file);
	fputs(string("\n").c_str(), file);
	fputs(mscnProblem->sf->toString().c_str(), file);
	fputs(string("\n").c_str(), file);
	fputs(mscnProblem->sm->toString().c_str(), file);
	fputs(string("\n").c_str(), file);
	fputs(mscnProblem->ss->toString().c_str(), file);
	fputs(string("\n").c_str(), file);

	//fputs(string("\n").c_str(), file);

	fputs(mscnProblem->ud->toString().c_str(), file);
	fputs(string("\n").c_str(), file);
	fputs(mscnProblem->uf->toString().c_str(), file);
	fputs(string("\n").c_str(), file);
	fputs(mscnProblem->um->toString().c_str(), file);
	fputs(string("\n").c_str(), file);

	fputs(mscnProblem->ps->toString().c_str(), file);
	fputs(string("\n").c_str(), file);

	//fputs(string("\n").c_str(), file);

	fputs(mscnProblem->cd->toString().c_str(), file);
	fputs(string("\n").c_str(), file);
	fputs(mscnProblem->cf->toString().c_str(), file);
	fputs(string("\n").c_str(), file);
	fputs(mscnProblem->cm->toString().c_str(), file);
	fputs(string("\n").c_str(), file);

	//fputs(string("\n").c_str(), file);

	

	//fputs(string("\n").c_str(), file);

	fputs(mscnProblem->xdMin->toString().c_str(), file);	
	fputs(string("\n").c_str(), file);
	fputs(mscnProblem->xdMax->toString().c_str(), file);
	fputs(string("\n").c_str(), file);
	fputs(mscnProblem->xfMin->toString().c_str(), file);
	fputs(string("\n").c_str(), file);
	fputs(mscnProblem->xfMax->toString().c_str(), file);
	fputs(string("\n").c_str(), file);
	fputs(mscnProblem->xmMin->toString().c_str(), file);
	fputs(string("\n").c_str(), file);
	fputs(mscnProblem->xmMax->toString().c_str(), file);



	return true;
}

bool FileManager::openToRead(string fileName)
{
	if (file != NULL) {
		close();
	}
	file = fopen(fileName.c_str(), "r+");
	if (file == NULL) return false;
	return true;
}

bool FileManager::openToWrite(string fileName)
{
	if (file != NULL) close();
	file = fopen(fileName.c_str(), "w+");
	if (file == NULL) return false;
	return true;
}

bool FileManager::close()
{
	if (file == NULL) return false;
	fclose(file);
	if (file != NULL) return false;
	return true;
}


FileManager::~FileManager()
{
	if (file != NULL) close();
}



MscnProblem* FileManager::read()
{
	
	char line[500];


	fgets(line, 500, file);
	//cout<<string(line);
	string line1(line);
	regex reg(";");
	regex_replace(ostreambuf_iterator<char>(std::cout), line1.begin(), line1.end(), reg, " ");
	line1.erase(remove_if(line1.begin(), line1.end(), ::isspace), line1.end());
	int deliverersNumber = stoi(line1);


	fgets(line, 500, file);
	string line2(line);
	
	regex_replace(ostreambuf_iterator<char>(std::cout), line2.begin(), line2.end(), reg, " ");
	line2.erase(remove_if(line2.begin(), line2.end(), ::isspace), line2.end());
	int factoriesNumber = stoi(line2);

	fgets(line, 500, file);
	string line3(line);
	
	regex_replace(ostreambuf_iterator<char>(std::cout), line3.begin(), line3.end(), reg, " ");
	line3.erase(remove_if(line3.begin(), line3.end(), ::isspace), line3.end());
	int magazinesNumber = stoi(string(line));

	fgets(line, 500, file);
	string line4(line);
	
	regex_replace(ostreambuf_iterator<char>(std::cout), line4.begin(), line4.end(), reg, " ");
	line4.erase(remove_if(line4.begin(), line4.end(), ::isspace), line4.end());
	int shopsNumber = stoi(string(line));
	

	fgets(line, 500, file);
	Table* sd = new Table(string(line), deliverersNumber); 

	fgets(line, 500, file);
	Table* sf = new Table(string(line), factoriesNumber);
	
	fgets(line, 500, file);	
	Table* sm = new Table(string(line), magazinesNumber);
	
	fgets(line, 500, file);
	Table* ss = new Table(string(line), shopsNumber);

	fgets(line, 500, file);
	Table* ud = new Table(string(line), deliverersNumber);

	fgets(line, 500, file);
	Table* uf = new Table(string(line), factoriesNumber);

	fgets(line, 500, file);
	Table* um = new Table(string(line), magazinesNumber);
	
	fgets(line, 500, file);
	Table* ps = new Table(string(line), shopsNumber);

	fgets(line, 500, file);
	Matrix* cd = new Matrix(string(line), deliverersNumber, factoriesNumber);

	fgets(line, 500, file);
	Matrix* cf = new Matrix(string(line), factoriesNumber, magazinesNumber);

	fgets(line, 500, file);
	Matrix* cm = new Matrix(string(line), magazinesNumber, shopsNumber);
	
	fgets(line, 500, file);
	Matrix* xdMin = new Matrix(string(line), deliverersNumber, factoriesNumber);

	fgets(line, 500, file);
	Matrix* xdMax = new Matrix(string(line), deliverersNumber, factoriesNumber);
	
	fgets(line, 500, file);
	Matrix* xfMin = new Matrix(string(line), factoriesNumber, magazinesNumber);
	
	fgets(line, 500, file);
	Matrix* xfMax = new Matrix(string(line), factoriesNumber, magazinesNumber);

	fgets(line, 500, file);
	Matrix* xmMin = new Matrix(string(line), magazinesNumber, shopsNumber);

	fgets(line, 500, file);
	Matrix* xmMax = new Matrix(string(line), magazinesNumber, shopsNumber);

	// modyfikacja

	/*
	fgets(line, 500, file);
	string line10(line);
	regex_replace(ostreambuf_iterator<char>(std::cout), line10.begin(), line10.end(), reg, " ");
	line10.erase(remove_if(line10.begin(), line10.end(), ::isspace), line10.end());
	double dfMin = stod(line10);


	fgets(line, 500, file);
	string line11(line);
	regex_replace(ostreambuf_iterator<char>(std::cout), line11.begin(), line11.end(), reg, " ");
	line11.erase(remove_if(line11.begin(), line11.end(), ::isspace), line11.end());
	double dfMax = stod(line11);

	// fm

	fgets(line, 500, file);
	string line12(line);
	regex_replace(ostreambuf_iterator<char>(std::cout), line12.begin(), line12.end(), reg, " ");
	line12.erase(remove_if(line12.begin(), line12.end(), ::isspace), line12.end());
	double fmMin = stod(line12);


	fgets(line, 500, file);
	string line13(line);
	regex_replace(ostreambuf_iterator<char>(std::cout), line13.begin(), line13.end(), reg, " ");
	line13.erase(remove_if(line13.begin(), line13.end(), ::isspace), line13.end());
	double fmMax = stod(line13);

	// ms

	fgets(line, 500, file);
	string line14(line);
	regex_replace(ostreambuf_iterator<char>(std::cout), line14.begin(), line14.end(), reg, " ");
	line14.erase(remove_if(line14.begin(), line14.end(), ::isspace), line14.end());
	double msMin = stod(line14);


	fgets(line, 500, file);
	string line15(line);
	regex_replace(ostreambuf_iterator<char>(std::cout), line15.begin(), line15.end(), reg, " ");
	line15.erase(remove_if(line15.begin(), line15.end(), ::isspace), line15.end());
	double msMax = stod(line15);

	double* dfMinH = new double(dfMin);
	double* dfMaxH = new double(dfMax);

	double* fmMinH = new double(fmMin);
	double* fmMaxH = new double(fmMax);

	double* msMinH = new double(msMin);
	double* msMaxH = new double(msMax);
	*/

	return new MscnProblem(sd, sf, sm, ss, ud, uf, um, ps, cd, cf, cm,
		xdMin,
		xdMax,
		xfMin,
		xfMax,
		xmMin,
		xmMax /*, dfMinH, dfMaxH, fmMinH, fmMaxH, msMinH, msMaxH */);

}

