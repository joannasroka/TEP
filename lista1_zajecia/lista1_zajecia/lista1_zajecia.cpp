// lista1_zajecia.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>

using namespace std;

int increase = 5; 

void allocTableAndAdd(int size) {
	if (size <= 0) return;
	int *tab;
	tab = new int[size];
	for (int i = 0; i < size; i++) {
		tab[i] = i + increase;
	}
	/*
	for (int k = 0; k < size; k++) {
		cout << tab[k] << ", ";
	}*/

	delete tab;
}

bool allocTable2Dim(int ***table, int sizeX, int sizeY) {
	if (sizeX <= 0 || sizeY <= 0 || table == NULL) return false;
	*table = new int *[sizeX];
	for (int i = 0; i < sizeX; i++) {
		(*table)[i] = new int[sizeY];
	}
	/*
	for (int k = 0; k < sizeX; k++) {
		for (int i = 0; i < sizeY; i++) {
			(*table)[k][i] = 1;
			cout << (*table)[k][i] << ", ";
		}
		cout << endl;
	}*/
	return true;
}

	bool allocTabDi(int ****table, int sizeX, int sizeY) {
		if (sizeX <= 0 || sizeY <= 0 || table == NULL) return false;
		*table = new int **[sizeX];
		for (int i = 0; i < sizeX; i++) {
			(*table)[i] = new int *[sizeY];
			for (int k = 0; k < sizeY; k++) {
				(*table)[i][k] = new int;
			}
		}
		/*
		for (int i = 0; i < sizeX; i++) {
			for (int k = 0; k < sizeY; k++) {
				for (int l = 0; l < sizeZ; l++) {
					(*table)[i][k][l] = 100*i+10*k+l;
					cout << (*table)[i][k][l] << ", ";
				}
			}
		}*/
		return true;
	}

	bool deallocTabDi(int ***table, int sizeX, int sizeY) {
		if (sizeX <= 0 || sizeY <= 0 || table == NULL) return false;
		for (int i = 0; i < sizeX; i++) {
			
			for (int j = 0; j < sizeY; j++) {
				delete table[i][j];
			}
			delete table[i];
		}
		delete table;
		return true;
	}



bool deallocTable(int **table, int sizeX) {
	if (sizeX <= 0  || table == NULL) return false;
	for (int i = 0; i < sizeX; i++) {
			delete table[i];
	}
	delete table;
	return true;
}



int main()
	// zaalokowac tablice trzywamiarowa za tydzien moze
	// sprawdz i_val = 0; a potem &i_val, &&i_val, itd..
	//c_lion da sie ustawic 98 cpp
{
	allocTableAndAdd(3);
	int **tab;
	allocTable2Dim(&tab, 2, 3);
	deallocTable(tab, 2);

	//int ***tab3D;

	//allocTable3Dim(&tab3D, 2, 3, 4);
	//deallocTable3D(tab3D, 2, 3);
  
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
