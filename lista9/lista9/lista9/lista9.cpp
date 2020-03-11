// lista9.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "Matrix.h"
#include "Table.h"
#include "MscnProblem.h"
#include "FileManager.h"

using namespace std;

void test() {
	double** cdHelp = new double*[2];
	cdHelp[0] = new double [2] { 1.0, 2.0 };
	cdHelp[1] = new double[2]{ 1.0, 0.0 };

	double** cfHelp = new double*[2];
	cfHelp[0] = new double[3]{ 0.0, 3.0, 1.0 };
	cfHelp[1] = new double[3]{ 2.0, 0.0, 1.0 };

	double** cmHelp = new double*[3];
	cmHelp[0] = new double[2]{ 0.5, 1.0 };
	cmHelp[1] = new double[2]{ 3.0, 2.0 };
	cmHelp[2] = new double[2]{ 3.0, 2.0 };
	
	Matrix* cd = new Matrix(cdHelp, 2, 2);
	Matrix* cf = new Matrix(cfHelp, 2, 3);
	Matrix* cm = new Matrix(cmHelp, 3, 2);

	double* udHelp = new double[2]{ 1.0, 2.0 };
	double* ufHelp = new double[2]{2.0, 1.0 };
	double* umHelp = new double[3]{ 0.0, 6.0, 1.0 };

	Table* ud = new Table(udHelp, 2);
	Table* uf = new Table(ufHelp, 2);
	Table* um = new Table(umHelp, 3);

	double* psHelp = new double[2]{ 3.0, 4.0, };
	Table* ps = new Table(psHelp, 2);

	double* solution = new double[16]
	{ 1.0, 2.0, 3.0, 2.0,
	2.5, 3.0, 1.0, 0.0, 0.0, 1.0,
	0.0, 1.0, 2.0, 1.0, 3.0, 2.0 };

	double* sdHelp = new double[2]{ 1.0, 2.0 };
	double* sfHelp = new double[2]{ 1.0, 2.0 };
	double* smHelp = new double[3]{ 1.0, 2.0, 3.0 };
	double* ssHelp = new double[2]{ 1.0, 2.0 };
	Table* sd = new Table(sdHelp, 2);
	Table* sf = new Table(sfHelp, 2);
	Table* sm = new Table(smHelp, 3);
	Table* ss = new Table(ssHelp, 2);


	double** xdMinHelp = new double*[2];
	xdMinHelp[0] = new double[2]{ 1.0, 2.0 };
	xdMinHelp[1] = new double[2]{ 3.0, 2.0 };
	
	double** xdMaxHelp = new double*[2];
	xdMaxHelp[0] = new double[2]{ 100.0, 200.0 };
	xdMaxHelp[1] = new double[2]{ 300.0, 222.0 };

	Matrix* xdMin = new Matrix(xdMinHelp, 2, 2);
	Matrix* xdMax = new Matrix(xdMaxHelp, 2, 2);




	double** xfMinHelp = new double*[2];
	xfMinHelp[0] = new double[3]{ 22.0, 21.0, 28.0 };
	xfMinHelp[1] = new double[3]{ 11.0, 12.0, 13.0 };

	double** xfMaxHelp = new double*[2];
	xfMaxHelp[0] = new double[3]{ 123.0, 230.0, 233.0 };
	xfMaxHelp[1] = new double[3]{ 390.0, 391.0, 392.0 };

	Matrix* xfMin = new Matrix(xfMinHelp, 2, 3);
	Matrix* xfMax = new Matrix(xfMaxHelp, 2, 3);



	double** xmMinHelp = new double*[3];
	xmMinHelp[0] = new double[2]{ 0.5, 0.25 };
	xmMinHelp[1] = new double[2]{ 0.05, 0.011 };
	xmMinHelp[2] = new double[2]{ 0.0112, 0.03111};

	double** xmMaxHelp = new double*[3];
	xmMaxHelp[0] = new double[2]{ 123.5, 230.5};
	xmMaxHelp[1] = new double[2]{ 390.5, 391.5};
	xmMaxHelp[2] = new double[2]{ 390.5, 391.5 };

	Matrix* xmMin = new Matrix(xmMinHelp, 3, 2);
	Matrix* xmMax = new Matrix(xmMaxHelp, 3, 2);
	
	/*
	double* dfMin = new double(1.0);
	double* dfMax = new double(2.0);

	double* fmMin = new double(3.0); // fabryki - magazyny
	double* fmMax = new double(4.0);

	double* msMin = new double(5.0); // magazyny - sklepy
	double* msMax = new double(6.0);
	*/



	int sizeSolution = 16;
	MscnProblem mscnProblem(sd, sf, sm, ss,  ud,  uf,  um,  ps,  cd,  cf,  cm,
		 xdMin,
		 xdMax,
		 xfMin,
		 xfMax,
		 xmMin,
		 xmMax
		/*, dfMin, dfMax, fmMin, fmMax, msMin, msMax*/);

	bool* isCorrect = new bool(true);
	//cout<< mscnProblem.getQuality(solution, sizeSolution, isCorrect);
	double* min = new double(0.0);
	double* max = new double(0.0);
	 mscnProblem.getMinMax(min, max, 10);
	 //cout << *min << " " << *max;

	 FileManager fileManager;
	 //fileManager.openToWrite("testZapisu.txt");
	 //fileManager.save(&mscnProblem);

	 //fileManager.close();

	
	 fileManager.openToRead("testZapisu.txt");

	 MscnProblem* odczyt = fileManager.read();

	
	cout << odczyt->getQuality(solution, sizeSolution, isCorrect);

	/*
	cout << "modyfikacja: " << endl;
	 odczyt->showModifi();
	 */

	cout << endl<< *isCorrect;

}

int main()
{
	test();
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
