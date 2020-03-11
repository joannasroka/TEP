#pragma once
#define DEF_TAB_SIZE 10 

using namespace std;

class Tab
{
public:
	Tab(); 
	Tab(const Tab& other);
	Tab(Tab &&other);

	Tab& operator=(const Tab& other); // moze tu byc Tab& lub void
	Tab& operator=(Tab &&other); // Tab& lub void

	~Tab();

	bool setSize(int newSize);
	int getSize() { return(size); }
private:
	void copy(const Tab& other);
	void moveHelper(Tab& other);

	int *pTab;
	int size;
};

