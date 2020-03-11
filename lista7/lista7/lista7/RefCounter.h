#pragma once

using namespace std;

class RefCounter
{
public:
	RefCounter() { count = 0; }
	
	int add() { return ++count; }
	int dec() { return --count; }
	int get() { return count;  }
private:
	int count;
};

