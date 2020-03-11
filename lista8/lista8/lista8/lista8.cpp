// lista8.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "Tab.h"
#include "TabDouble.h"
#include "Table.h"

using namespace std;

int main()
{
	/*
	Tab tab1;
	Tab tab2;
	tab2.setSize(6);

	tab1 = move(tab2);
	*/
	/*
	TabDouble doub1;
	TabDouble doub2(move(doub1));
	TabDouble doub3;
	doub3 = move(doub2);
	*/
	Table table1;
	Table table2(6, 3);
	Table table3(table1);
	Table table4(move(table2));
	Table table5(1, 2);

	table1 = table4;
	table1 = move(table5);


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
