#include "pch.h"
#include "FileThrowEx.h"
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable:4996)

FileThrowEx::FileThrowEx()
{
}

FileThrowEx::FileThrowEx(string fileName)
{
	openFile(fileName);
}

FileThrowEx::FileThrowEx(FileThrowEx & other)
{
	if (other.pFile == NULL) throw (-1);
	openFile(other.fileName + "_copy");
}


FileThrowEx::~FileThrowEx()
{
	if (pFile != NULL) closeFile();
}


void FileThrowEx::openFile(string fileName)
{
	if (pFile != NULL) {
		closeFile();
		throw (-1); 
	}

	pFile = fopen(fileName.c_str(), "w+");
	if (pFile == NULL) throw (-1);
	this->fileName = fileName;
}

void FileThrowEx::closeFile()
{
	if (pFile == NULL) throw (-1);
	int error = fclose(pFile);
	if (error != 0) throw (-1);
	pFile = NULL;
}

void FileThrowEx::printLine(string text)
{
	if (pFile == NULL) throw (-1);
	else {
		int error = fputs(text.c_str(), pFile);
		if (error < 0) throw (-1);
		copyText.push_back(text);
	}
}

void FileThrowEx::printManyLines(vector<string> text)
{
	for (vector <string>::iterator i = text.begin(); i != text.end(); i++) {
		printLine(*i);
	}
}

void FileThrowEx::makeChangesCopy(string destination)
{
	if (pFile == NULL) throw (-1);
	FILE* other;
	other = fopen(destination.c_str(), "w+");
	if (other == NULL) throw (-1);

	for (vector <string>::iterator j = copyText.begin(); j != copyText.end(); j++) {
		int error = fputs((*j).c_str(), pFile);
		if (error < 0) throw (-1);
		copyText.push_back(*j);
	}

	int error = fclose(other);
	if (error != 0) throw (-1);

	/*
	if (pFile == NULL) throw (-1);

	char buffer[100];

	while (!feof(pFile))
	{
		if (fgets(buffer, 100, pFile) != NULL) {
			fputs(buffer, stdout);
		}
	}
	closeFile();

	FILE* other;
	other = fopen(destination.c_str(), "w+");
	
	int error = fputs(buffer, pFile);
	if (error < 0) throw (-1);
	*/
}
