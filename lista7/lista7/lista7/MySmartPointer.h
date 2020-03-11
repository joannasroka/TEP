#pragma once
#include "RefCounter.h"
#include "IntClass.h"

using namespace std;

template <typename T> class MySmartPointer
{
public:
	MySmartPointer(T* pointer);
	MySmartPointer(T* arrayPointer, int size);
	MySmartPointer(const MySmartPointer& otherSmartPointer);
	MySmartPointer(T* arrayPointer[], int size);
	~MySmartPointer();

	T* getPointer() const;
	//const T** getArrayPointer();
	void showArray();
	int getCounter();

	T& operator*() { return (*pointer); }
	T* operator->() { return pointer; }

	T get(int index);

	void operator=(const MySmartPointer& otherSmartPointer);

	void copyPointer(const MySmartPointer& otherSmartPointer);
	void decreasePointer();
	void decreaseArrayPointer();

private:
	T* pointer;
	RefCounter* counter;
	int arraySize = 0;
};

template <typename T>
MySmartPointer<T>::MySmartPointer(T* pointer) {
	this->pointer = pointer;
	counter = new RefCounter();
	counter->add();
}

template <typename T>
MySmartPointer<T>::MySmartPointer(const MySmartPointer& otherSmartPointer) {
	if (otherSmartPointer.arraySize != 0) {
		this->pointer = otherSmartPointer.pointer;
		this->arraySize = otherSmartPointer.arraySize;
	}
	else this->pointer = otherSmartPointer.pointer;
	this->counter = otherSmartPointer.counter;
	counter->add();

}

template <typename T>
MySmartPointer<T>::MySmartPointer(T* arrayPointer[], int size) {
	if (size <= 0) throw (-1);
	arraySize = size;
	this->pointer = *arrayPointer; 
	counter = new RefCounter();
	counter->add();
}

template <typename T>
MySmartPointer<T>::MySmartPointer(T* arrayPointer, int size) {
	if (size <= 0) throw (-1);
	arraySize = size;
	this->pointer = arrayPointer;
	counter = new RefCounter();
	counter->add();
}

template <typename T>
MySmartPointer<T>::~MySmartPointer() {
	if (arraySize > 0) {
		decreaseArrayPointer();
	}
	else decreasePointer();
}

template <typename T>
void MySmartPointer<T>::copyPointer(const MySmartPointer& otherSmartPointer) {
	if (otherSmartPointer.arraySize != 0) {
		arraySize = otherSmartPointer.arraySize;
		this->pointer = otherSmartPointer.pointer;
	}
	else this->pointer = otherSmartPointer.getPointer();

	this->counter = otherSmartPointer.counter;
	counter->add();
}

template <typename T>
void MySmartPointer<T>::decreasePointer() {
	if (counter->get() == 1) {
		delete pointer;
		delete counter;
	}
	else {
		counter->dec();
	}
}

template <typename T>
void MySmartPointer<T>::decreaseArrayPointer() {
	if (counter->get() == 1) {
		delete [] pointer;
		delete counter;
	}
	else {
		counter->dec();
	}
}

template <typename T>
void MySmartPointer<T>::operator=(const MySmartPointer& otherSmartPointer) {
	if (counter->get() == 0) {
		copyPointer(otherSmartPointer);
	}
	else {
		if (arraySize != 0) { decreaseArrayPointer(); }
		else decreasePointer();
		copyPointer(otherSmartPointer);
	}
}


template <typename T>
T* MySmartPointer<T>::getPointer() const {
	return pointer;
}


template <typename T>
void MySmartPointer<T>::showArray() {
	cout << ".";
}

template <>
void MySmartPointer<IntClass>::showArray() {
	for (int i = 0; i < arraySize; i++) {
		cout << pointer[i].getValue() << " ";
	}

}

/*
template <typename T>
const T** MySmartPointer<T>::getArrayPointer() {
	T** superPointer = &pointer;
	return superPointer;
}
*/
template <typename T>
int MySmartPointer<T>::getCounter() {
	return counter->get();
}

template <typename T>
T MySmartPointer<T>::get(int index) {
	if (index < 0 || index >= arraySize) throw (-1);
	return pointer[index];
}




