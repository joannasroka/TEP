#pragma once
#include "RefCounter.h"

using namespace std;

template <typename T> class MySmartPointer
{
public:
	MySmartPointer(T* pointer);
	MySmartPointer(const MySmartPointer<T>& otherSmartPointer);
	~MySmartPointer();

	T* getPointer() const;
	int getCounter();

	T& operator*() { return (*pointer); }
	T* operator->() { return pointer; }

	void operator=(const MySmartPointer<T>& otherSmartPointer);

	void copyPointer(const MySmartPointer<T>& otherSmartPointer);
	void decreasePointer();

private:
	T* pointer;
	RefCounter<T>* counter;
};

template <typename T>
MySmartPointer<T>::MySmartPointer(T* pointer) {
	this->pointer = pointer;
	counter = new RefCounter<T>();
	//counter->add();
	counter->addPointer(*this);
}

template <typename T>
MySmartPointer<T>::~MySmartPointer() {
	decreasePointer();
}

template <typename T>
void MySmartPointer<T>::copyPointer(const MySmartPointer<T>& otherSmartPointer) {
	this->pointer = otherSmartPointer.getPointer();
	this->counter = otherSmartPointer.counter;
	//counter->add();
	counter->addPointer(*this);
}

template <typename T>
void MySmartPointer<T>::decreasePointer() {
	if (counter->get() == 1) {
		delete pointer;
		delete counter;
	}
	else {
		//counter->dec();
		counter->removePointer(*this);
	}
}

template <typename T>
void MySmartPointer<T>::operator=(const MySmartPointer<T>& otherSmartPointer) {
	if (counter->get() == 0) {
		copyPointer(otherSmartPointer);
	}
	else {
		decreasePointer();
		copyPointer(otherSmartPointer);
	}
}


template <typename T>
MySmartPointer<T>::MySmartPointer(const MySmartPointer<T>& otherSmartPointer) {
	this->pointer = otherSmartPointer.getPointer();
	this->counter = otherSmartPointer.counter;
	//counter->add();
	counter->addPointer(*this);

}

template <typename T>
T* MySmartPointer<T>::getPointer() const {
	return pointer;
}

template <typename T>
int MySmartPointer<T>::getCounter() {
	return counter->get();
}