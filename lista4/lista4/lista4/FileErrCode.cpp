#include "pch.h"
#include "FileErrCode.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable:4996)


FileErrCode::FileErrCode()
{
}

FileErrCode::FileErrCode(string fileName, bool* errCode)
{
	*errCode = openFile(fileName);
}


FileErrCode::~FileErrCode()
{
	if (pFile != NULL) closeFile();
}

bool FileErrCode::openFile(string fileName)
{
	if (pFile != NULL) {
		closeFile();
		return false;
	}
	pFile = fopen(fileName.c_str(), "w+");
	return (pFile != NULL);
}

bool FileErrCode::closeFile()
{
	if (pFile == NULL) return false;
	int error = fclose(pFile);
	return (error == 0);
}

bool FileErrCode::printLine(string text)
{
	if (pFile == NULL) return false;
	int error = fputs(text.c_str(), pFile);
	return (error == 0);
	
}

bool FileErrCode::printManyLines(vector<string> text)
{
	for (vector <string>::iterator i = text.begin(); i != text.end(); i++) {
		if (!printLine(*i)) return false;
	}
	return true;
}
