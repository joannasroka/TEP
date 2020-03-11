#pragma once
#include <cstdio>
#include "MscnProblem.h"
#include <regex>

using namespace std;

class FileManager
{
public:
	FileManager();
	
	bool save(MscnProblem* mscnProblem);

	MscnProblem* read();

	bool openToRead(string fileName);
	bool openToWrite(string fileName);

	bool close();

	~FileManager();

private:
	FILE* file;


};

