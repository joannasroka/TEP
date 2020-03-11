// lista5.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "NodeStatic.h"
#include "TreeStatic.h"
#include "TreeDynamic.h"
#include "NodeDynamic.h"

using namespace std;

void nodeTest()
{

	NodeDynamic<int> root;
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

	//root.printAllBelow();
	//cout << root.getChild(0)->getDegree() << endl;
	//cout << root.getChild(1)->getChild(1)->getDegree();

	int* max = new int(0);
	root.getMax(max);
	cout << *max;

}

void maxTest() {

	TreeDynamic<int> tree1;
	tree1.getRoot()->setValue(11);
	tree1.getRoot()->addNewChild();
	tree1.getRoot()->addNewChild();
	tree1.getRoot()->getChild(0)->setValue(24);
	tree1.getRoot()->getChild(1)->setValue(5);

	tree1.getRoot()->getChild(0)->addNewChild();
	tree1.getRoot()->getChild(0)->addNewChild();
	tree1.getRoot()->getChild(0)->getChild(0)->setValue(1);
	tree1.getRoot()->getChild(0)->getChild(1)->setValue(-3);

	tree1.getRoot()->getChild(1)->addNewChild();
	tree1.getRoot()->getChild(1)->addNewChild();
	tree1.getRoot()->getChild(1)->getChild(0)->setValue(4);
	tree1.getRoot()->getChild(1)->getChild(1)->setValue(11);

	int* max = tree1.getMax();
	cout << *max;

}

void moveTreeTest() {


	TreeDynamic<string> tree1;
	tree1.getRoot()->setValue("A");
	tree1.getRoot()->addNewChild();
	tree1.getRoot()->addNewChild();
	tree1.getRoot()->getChild(0)->setValue("Aa");
	tree1.getRoot()->getChild(1)->setValue("Ab");

	tree1.getRoot()->getChild(0)->addNewChild();
	tree1.getRoot()->getChild(0)->addNewChild();
	tree1.getRoot()->getChild(0)->getChild(0)->setValue("Aaa");
	tree1.getRoot()->getChild(0)->getChild(1)->setValue("Aab");

	tree1.getRoot()->getChild(1)->addNewChild();
	tree1.getRoot()->getChild(1)->addNewChild();
	tree1.getRoot()->getChild(1)->getChild(0)->setValue("Aba");
	tree1.getRoot()->getChild(1)->getChild(1)->setValue("Abb");


	TreeDynamic<string> tree2;
	tree2.getRoot()->setValue("X");
	tree2.getRoot()->addNewChild();
	tree2.getRoot()->addNewChild();
	tree2.getRoot()->addNewChild();
	tree2.getRoot()->getChild(0)->setValue("XA");
	tree2.getRoot()->getChild(1)->setValue("XB");
	tree2.getRoot()->getChild(2)->setValue("XC");

	tree2.getRoot()->getChild(1)->addNewChild();
	tree2.getRoot()->getChild(1)->addNewChild();
	tree2.getRoot()->getChild(1)->getChild(0)->setValue("XBa");
	tree2.getRoot()->getChild(1)->getChild(1)->setValue("XBb");

	tree2.getRoot()->getChild(1)->getChild(1)->addNewChild();
	tree2.getRoot()->getChild(1)->getChild(1)->addNewChild();
	tree2.getRoot()->getChild(1)->getChild(1)->getChild(0)->setValue("XBba");
	tree2.getRoot()->getChild(1)->getChild(1)->getChild(1)->setValue("XBbb");


	cout << "przed: " << endl;

	//tree1.printTree();
	vector <int> nodesDegree1;
	//cout << tree2.getRoot()->getTreeDegree(nodesDegree1);

	tree1.printTreeInBreadth();


	tree1.moveSubtree(tree1.getRoot()->getChild(1), tree2.getRoot()->getChild(1)->getChild(1));

	cout << endl << "po: " << endl;

	vector <int> nodesDegree2;
	//cout << tree2.getRoot()->getTreeDegree(nodesDegree2);




	//tree1.printTree();
	
	

}

void sumTreeTest() {
	TreeDynamic<string> tree2;
	tree2.getRoot()->setValue("X");
	tree2.getRoot()->addNewChild();
	tree2.getRoot()->addNewChild();
	tree2.getRoot()->addNewChild();
	tree2.getRoot()->getChild(0)->setValue("XA");
	tree2.getRoot()->getChild(1)->setValue("XB");
	tree2.getRoot()->getChild(2)->setValue("XC");

	tree2.getRoot()->getChild(1)->addNewChild();
	tree2.getRoot()->getChild(1)->addNewChild();
	tree2.getRoot()->getChild(1)->getChild(0)->setValue("XBa");
	tree2.getRoot()->getChild(1)->getChild(1)->setValue("XBb");

	tree2.getRoot()->getChild(1)->getChild(1)->addNewChild();
	tree2.getRoot()->getChild(1)->getChild(1)->addNewChild();
	tree2.getRoot()->getChild(1)->getChild(1)->getChild(0)->setValue("XBba");
	tree2.getRoot()->getChild(1)->getChild(1)->getChild(1)->setValue("XBbb");

	string* result = new string("");
	tree2.sum(result);
	//cout << *result;

	cout<< tree2.nodesCount();
}


int main()
{
	moveTreeTest();
	//maxTest();
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
