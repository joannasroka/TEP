// lista7.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "MySmartPointer.h"
#include "IntClass.h"

using namespace std;

int main()
{
	IntClass* array = new IntClass[3];
	for (int i = 0; i < 3; i++) {
		array[i] = IntClass(i);
	}

	IntClass** table = new IntClass*[10];

	IntClass* cos = new IntClass(7);

	MySmartPointer<IntClass> pointer(&array, 3);

	//cout << pointer.get(1).getValue();
	cout << endl;

	MySmartPointer<IntClass> pointer2(pointer);
	//cout << pointer.getCounter();

	MySmartPointer <IntClass*> pointer3(new IntClass*(new IntClass(3)));
	MySmartPointer <IntClass> pointer4(new IntClass[3], 3);

	MySmartPointer <IntClass*> pointer5(table);


	//cout << pointer3.getCounter();

	//cout << pointer.get(1).getValue() << endl;
	pointer = pointer4;
	//cout << pointer.get(1).getValue();


	cout << pointer3.getCounter() << endl;

	pointer5 = pointer3;

	cout << pointer3.getCounter();

	cout << endl;

	//pointer.showArray();


	//IntClass** pointer = new IntClass*[10];
	//IntClass** pointer2 = new IntClass*[3];



	//MySmartPointer<IntClass> smartPointer1 (pointer, 10);
	//MySmartPointer<IntClass> smartPointer2(smartPointer1);

	//MySmartPointer<IntClass> smartPointer3(pointer2, 3);
	//cout << smartPointer3.getCounter() << endl;
	//smartPointer3 = smartPointer2;
	//cout << smartPointer3.getCounter() << endl;

	//cout<< (smartPointer1.getPointer() == smartPointer3.getPointer());


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
