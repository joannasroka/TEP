#pragma once
#include <string>
#include <vector>

using namespace std;

class FileLastError
{
private:
	bool lastError;
	FILE *pFile;
	string open = "w+";
public:
	bool getLastError() { return lastError; }

	FileLastError();
	FileLastError(string fileName);
	~FileLastError();

	void openFile(string fileName);
	void closeFile();
	void printLine(string text);
	void printManyLines(vector <string> text);
};

