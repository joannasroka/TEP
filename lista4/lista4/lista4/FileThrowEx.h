#pragma once
#include <string>
#include <vector>

using namespace std;

class FileThrowEx
{
private:
	FILE *pFile;
	string fileName;
	string open = "w+";

	vector<string> copyText;
public:
	FileThrowEx();
	FileThrowEx(string fileName);
	FileThrowEx(FileThrowEx& other);
	~FileThrowEx();

	void openFile(string fileName);
	void closeFile();
	void printLine(string text);
	void printManyLines(vector <string> text);

	void makeChangesCopy(string destination);

};

