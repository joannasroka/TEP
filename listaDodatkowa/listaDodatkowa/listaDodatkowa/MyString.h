#pragma once
#include <string>

using namespace std;

class MyString
{
public:
	MyString();
	MyString(const MyString& other);
	MyString(string text);
	~MyString();

	MyString& operator=(string text);
	MyString& operator=(const MyString& other);

	MyString operator+(string text);
	MyString operator+(const MyString& other);

	MyString& operator+=(string text);

	MyString operator-(string text);
	MyString& operator-=(string text);

	MyString operator*(string text);
	MyString& operator*=(string text);

	friend MyString operator+(const string text, const MyString& other);
	friend MyString operator+( const MyString& other, const string text);
	friend ostream& operator<<(ostream& out, const MyString& myString);

	bool setNewSize(int newSize);

	string sToStandard();


	explicit operator bool();

private:
	char* myString;
	int stringSize; 
};

