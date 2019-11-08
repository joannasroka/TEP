// lista4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include "FileLastError.h"
#include "FileErrCode.h"
#include "FileThrowEx.h"

#pragma warning(disable:4996)

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif



using namespace std;

int nTimes = 10;

vector<string> createVector(string text) {
	vector<string> vect;
	for (int i = 0; i < nTimes; i++) {
		vect.push_back(text);
	}
	return vect;
}


// zwraca false, gdy wystapi blad
/*
bool nTimesLastError(string fileName, string text) {
	FileLastError lastError;
	lastError.openFile(fileName);
	if (lastError.getLastError()) return false;

	vector<string> vect = createVector(text);
	lastError.printManyLines(vect);
	if (lastError.getLastError()) return false;

	lastError.closeFile();
	if (lastError.getLastError()) return false;
	return true;
}

void nTimesThrowEx(string fileName, string text) {
	FileThrowEx throwEx;
	try {
		throwEx.openFile(fileName);
		vector<string> vect = createVector(text);
		throwEx.printManyLines(vect);
		throwEx.closeFile();
	}
	catch (int e) {
		throw e;
	}
}

bool nTimesErrCode(string fileName, string text) {
	FileErrCode errCode;
	vector <string> vect = createVector(text);
	return (errCode.openFile(fileName) && errCode.printManyLines(vect) && errCode.closeFile());

}


*/

int main()
{
	string fileName = "costam.txt";

	string text = "a";

	FileErrCode errCode;
	cout<<errCode.openFile("test.txt");
	cout << errCode.printLine("Asia");


	/*
	bool errCode = nTimesErrCode(fileName, text);
	bool lastErr = nTimesLastError(fileName, text);
	bool throwEx = false;
	try {
		nTimesThrowEx(fileName, text);
		throwEx = true;
	}
	catch (int e) {
		throwEx = false;
	}
	cout << errCode << lastErr << throwEx;
	*/

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
