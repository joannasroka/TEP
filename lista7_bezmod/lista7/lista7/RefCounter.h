#pragma once
#include <vector>
#include "MySmartPointer.h"

using namespace std;

template <typename T> class MySmartPointer; // cykliczna referencja

template <typename T> class RefCounter
{
public:
	RefCounter() { count = 0; }

	int add() { return ++count; }
	int dec() { return --count; }
	int get() { return count; }

	void addPointer(MySmartPointer<T>& smartPointer);

	int getIndex(MySmartPointer<T>& smartPointer);

	void removePointer(MySmartPointer<T>& smartPointer);


private:
	int count;
	vector <MySmartPointer<T>*> smartPointers;
};

template <typename T> 
void RefCounter<T>::addPointer(MySmartPointer<T>& smartPointer) {
	add();
	smartPointers.push_back(&smartPointer);
}

template <typename T>
int RefCounter<T>::getIndex(MySmartPointer<T>& smartPointer) {

	int index = 0;
	typename vector <MySmartPointer<T>*>::iterator i;
	for (typename vector <MySmartPointer<T>*>::iterator i = smartPointers.begin(); i != smartPointers.end(); i++) {
		if ((*i) == &smartPointer) return index;
		index++;
	}
	return -1;
}

template <typename T>
void RefCounter<T>::removePointer(MySmartPointer<T>& smartPointer) {
	int index = getIndex(smartPointer);
	if (index != -1) {
		smartPointers.erase(smartPointers.begin()+index);
		dec();
	}
} 