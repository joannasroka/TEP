// lista2_zajecia.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "Table.h"

using namespace std;
/*
void modTab(Table *pTab, int newSize) {
	//(*pTab).setNewSize(newSize);
	pTab->setNewSize(newSize);
}
void modTab(Table tab, int newSize) {
	tab.setNewSize(newSize);
}
*/
int main()
{
	/*
	Table table ("Asia", 5);
	//modTab(&table, 9);
	//cout << endl<< table.getSize() << endl;
	modTab(table, 6);
	cout << endl<< table.getSize();

	//Table tableOfTable [3];
	//Table* pTableOfTable = new Table[3];
	//delete[] pTableOfTable;

	Table* table2 = new Table();
	table2 = table.pCloneReverse();
	*/


	// lista 3

	
	Table table0, table1;
	table0.setNewSize(6);

	for (int i = 0; i < table0.getSize(); i++) {
		table0.setValueAt(i, i + 1);
	}

	table1.setNewSize(4);

	for (int i = 0; i < table1.getSize(); i++) {
		table1.setValueAt(i, i + 2);
	}

	//table0 = table1;
	
	table1.setValueAt(2, 123);
	table0.print();
	table1.print();

	Table table2 = (table0 - table1);

	table2.print();
	
	
	// lista 8





	
	// zgloszony wyjatek: naruszenie zasad dostepu
	// poniewaz przy wyjsciu ze scope'a urachamiany jest podwojnie destruktor
	// i probuje uzyskac wartosc na ktora wskazuje name, a on juz wskazuje na cos co jest oznaczone jako zwolniona pamiec
	// wiec wywala blad
	// bo oba obiekty wspodziela te same imie i tablice

	// jak usunelam destruktor, to kompilator nie wywalal bledu przy tym, bo oba obiekty nie chca juz zwolnic TEGO SAMEGO miejsca w pamieci
	// bo nie zwalniaja zadnego
	// ale to nie znaczy, ze jest git








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
