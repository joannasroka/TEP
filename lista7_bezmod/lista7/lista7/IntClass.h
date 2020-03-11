#pragma once
class IntClass
{
public:
	IntClass(int value) { this->value = value; }
	int getValue() { return value; }
	void changeValue(int other) { this->value = other; }
private:
	int value;
};
