#include "pch.h"
#include "FileLastError.h"
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable:4996)

using namespace std;


FileLastError::FileLastError()
{
	lastError = false;
}

FileLastError::FileLastError(string fileName)
{
	openFile(fileName);
}


FileLastError::~FileLastError()
{
	if (pFile != NULL) closeFile();
}

void FileLastError::openFile(string fileName)
{
	lastError = false;

	if (pFile != NULL) {
		closeFile();
		lastError = true;
		return;
	}

	pFile = fopen(fileName.c_str(), "w+");
	if (pFile == NULL) lastError = true;
}

void FileLastError::closeFile()
{ //sprawdz czy pFile po zamknieciu jest NULLem czy nie
	lastError = false;
	if (pFile == NULL) {
		lastError = true;
		return;
	}
	int error = fclose(pFile);
	if (error != 0) lastError = true;
	pFile = NULL;
}

void FileLastError::printLine(string text)
{
	lastError = false;
	if (pFile == NULL) lastError = true;
	else {
		int error = fputs(text.c_str(), pFile);
		if (error < 0) lastError = true;
	}

}

void FileLastError::printManyLines(vector<string> text)
{
	for (vector <string>::iterator i = text.begin(); i != text.end(); i++) {
		printLine(*i);
		if (lastError) return;
	}
}
