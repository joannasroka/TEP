#pragma once
#define DEF_DOUBLE 6.66

using namespace std;

class TabDouble
{
public:
	TabDouble();
	TabDouble(const TabDouble& other);
	TabDouble(TabDouble&& other);

	TabDouble& operator=(const TabDouble& other);
	TabDouble& operator=(TabDouble&& other);

	~TabDouble();
private:
	double* pDoub;
};

