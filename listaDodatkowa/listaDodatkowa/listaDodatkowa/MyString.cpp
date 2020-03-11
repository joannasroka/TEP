#include "pch.h"
#include "MyString.h"

#define DEF_SIZE 0


MyString::MyString()
{
	myString = NULL;
	stringSize = DEF_SIZE;
}

MyString::MyString(const MyString & other)
{
	stringSize = other.stringSize;
	myString = new char[stringSize];
	for (int i = 0; i < stringSize; i++) {
		myString[i] = other.myString[i];
	}

}

MyString::MyString(string text)
{
	stringSize = text.length();
	myString = new char[stringSize];
	for (int i = 0; i < stringSize; i++) {
		myString[i] = text[i];
	}
}


MyString::~MyString()
{
	delete[] myString;
}

MyString& MyString::operator=(string text)
{
	if (myString != NULL) delete[] myString;
	stringSize = text.length();
	myString = new char[stringSize];
	for (int i = 0; i < stringSize; i++) {
		myString[i] = text[i];
	}
	return *this;
}

MyString& MyString::operator=(const MyString & other)
{
	if (myString != NULL) delete[] myString;
	stringSize = other.stringSize;

	myString = new char[stringSize];
	for (int i = 0; i < stringSize; i++) {
		myString[i] = other.myString[i];
	}
	return *this;
}

MyString MyString::operator+(string text)
{
	MyString result;

	result.myString = new char[stringSize + text.length()];
	result.stringSize = this->stringSize + text.length();

	for (int i = 0; i < stringSize; i++) {
		result.myString[i] = this->myString[i];
	}
	for (int j = 0; j < text.length(); j++) {
		result.myString[j + stringSize] = text[j];
	}

	return result;
}

MyString MyString::operator+(const MyString & other)
{
	MyString result(*this);
	int oldSize = stringSize;
	result.setNewSize(stringSize + other.stringSize);

	for (int i = 0; i++; i < other.stringSize) {
		result.myString[i + oldSize] = other.myString[i];
	}
	return result;

}

MyString& MyString::operator+=(string text)
{
	*this = *this + text;
	return *this;

}
MyString MyString::operator-(string text)
{
	string myText = "";
	for (int i = 0; i < stringSize; i++) {
		myText += myString[i];
	}

	int whereIsText = myText.find(text);
	if (whereIsText != string::npos) {
		stringSize -= text.length();
		myText.erase(whereIsText,text.length());
		if (myString != NULL) delete[] myString;
		myString = new char[stringSize];
		for (int i = 0; i < stringSize; i++) {
			myString[i] = myText[i];
		}

	}
	return *this;
}
MyString & MyString::operator-=(string text)
{
	*this = *this - text;
	return *this;
}
MyString MyString::operator*(string text)
{
	string myText = "";
	for (int i = 0; i < stringSize; i++) {
		myText += myString[i];
	}

	int whereIsText = myText.find(text);

	if (whereIsText != string::npos) {
		stringSize = text.length();
		myText = text;

		if (myString != NULL) delete[] myString;

		myString = new char[stringSize];
		for (int i = 0; i < stringSize; i++) {
			myString[i] = myText[i];
		}

	}
	else {
		stringSize = 0;
		if (myString != NULL) delete[] myString;
		myString = NULL;
	}
	return *this;
}
MyString & MyString::operator*=(string text)
{
	*this = *this * text;
	return *this;
}
bool MyString::setNewSize(int newSize)
{
	if (newSize <= 0) return false;

	char *newMyString = new char[newSize];
	int minTableLen = (newSize < stringSize) ? newSize : stringSize;
	for (int i = 0; i < minTableLen; i++) {
		newMyString[i] = myString[i];
	}
	delete[] myString;
	myString = newMyString;
	stringSize = newSize;
	return true;
}

string MyString::sToStandard()
{
	string result = "";
	for (int i = 0; i < stringSize; i++) {
		result += myString[i];
	}
	return result;
}




MyString::operator bool()
{
	return(stringSize != 0);
}



MyString operator+(const string text, const MyString& other)
{
	int newSize = text.length() + other.stringSize;
	MyString result;
	result.setNewSize(newSize);
	for (int i = 0; i < text.length(); i++) {
		result.myString[i] = text[i];
	}
	for (int j = 0; j < other.stringSize; j++) {
		result.myString[j + text.length()] = other.myString[j];
	}
	return result;
}

MyString operator+(const MyString & other, const string text)
{
	int newSize = text.length() + other.stringSize;
	MyString result;
	result.setNewSize(newSize);

	for (int j = 0; j < other.stringSize; j++) {
		result.myString[j] = other.myString[j];
	}
	for (int i = 0; i < text.length(); i++) {
		result.myString[i+other.stringSize] = text[i];
	}
	
	return result;
}

ostream & operator<<(ostream & out, const MyString & myString)
{
	for (int i = 0; i < myString.stringSize; i++) {
		out << myString.myString[i];
	}
	return out;
}
