// lista5.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "NodeStatic.h"
#include "TreeStatic.h"

using namespace std;

void treeTest()
{
	NodeStatic root;
	root.addNewChild();
	root.addNewChild();
	root.getChild(0)->setValue(1);
	root.getChild(1)->setValue(2);
	root.getChild(0)->addNewChild();
	root.getChild(0)->addNewChild();
	root.getChild(0)->getChild(0)->setValue(11);
	root.getChild(0)->getChild(1)->setValue(12);
	root.getChild(1)->addNewChild();
	root.getChild(1)->addNewChild();
	root.getChild(1)->getChild(0)->setValue(21);
	root.getChild(1)->getChild(1)->setValue(22);


	cout<< root.getChild(0)->getDeph();
	//root.printWithDeep(0);
	//root.getChild(0)->getChild(1)->printUp();
}


int main()
{
	treeTest();

	TreeStatic treeStatic1;
	treeStatic1.getRoot()->setValue(0);
	treeStatic1.getRoot()->addNewChild();
	treeStatic1.getRoot()->addNewChild();
	treeStatic1.getRoot()->getChild(0)->setValue(1);
	treeStatic1.getRoot()->getChild(1)->setValue(2);

	treeStatic1.getRoot()->getChild(0)->addNewChild();
	treeStatic1.getRoot()->getChild(0)->addNewChild();
	treeStatic1.getRoot()->getChild(0)->getChild(0)->setValue(11);
	treeStatic1.getRoot()->getChild(0)->getChild(1)->setValue(12);

	treeStatic1.getRoot()->getChild(1)->addNewChild();
	treeStatic1.getRoot()->getChild(1)->addNewChild();
	treeStatic1.getRoot()->getChild(1)->getChild(0)->setValue(21);
	treeStatic1.getRoot()->getChild(1)->getChild(1)->setValue(22);



	TreeStatic treeStatic2;
	treeStatic2.getRoot()->setValue(10);
	treeStatic2.getRoot()->addNewChild();
	treeStatic2.getRoot()->addNewChild();
	treeStatic2.getRoot()->addNewChild();
	treeStatic2.getRoot()->getChild(0)->setValue(100);
	treeStatic2.getRoot()->getChild(1)->setValue(200);
	treeStatic2.getRoot()->getChild(2)->setValue(300);

	treeStatic2.getRoot()->getChild(1)->addNewChild();
	treeStatic2.getRoot()->getChild(1)->addNewChild();
	treeStatic2.getRoot()->getChild(1)->getChild(0)->setValue(201);
	treeStatic2.getRoot()->getChild(1)->getChild(1)->setValue(202);
	
	treeStatic2.getRoot()->getChild(1)->getChild(1)->addNewChild();
	treeStatic2.getRoot()->getChild(1)->getChild(1)->addNewChild();
	treeStatic2.getRoot()->getChild(1)->getChild(1)->getChild(0)->setValue(203);
	treeStatic2.getRoot()->getChild(1)->getChild(1)->getChild(1)->setValue(204);

	cout << "przed: " << endl;

	//treeStatic2.printTree();

	treeStatic1.moveSubtree(treeStatic1.getRoot()->getChild(1), treeStatic2.getRoot()->getChild(1)->getChild(1));

	cout << endl << "po: " << endl;

	//treeStatic2.printTree();




	
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
