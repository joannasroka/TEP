#pragma once
class FileLastError
{
private:
	static bool lastError;

public:
	FileLastError();
	~FileLastError();
	FileLastError(string fileName);

	static bool getLastError(static bool lastError);
};

