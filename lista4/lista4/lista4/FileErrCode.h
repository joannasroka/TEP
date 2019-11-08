#pragma once
#include <string>
#include <vector>

using namespace std;

class FileErrCode
{
private:
	FILE *pFile;
	string open = "w+";
public:
	FileErrCode();
	FileErrCode(string fileName, bool* errCode);
	~FileErrCode();

	bool openFile(string fileName);
	bool closeFile();
	bool printLine(string text);
	bool printManyLines(vector <string> text);


};

