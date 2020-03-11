#pragma once
#pragma once
#define DEF_SIZEX 2
#define DEF_SIZEY 3

using namespace std;
class Table
{
public:
public:
	Table();
	Table(int newSizeX, int newSizeY);
	Table(const Table& other);
	Table(Table&& other);

	Table& operator=(const Table& other); // moze tu byc Tab& lub void
	Table& operator=(Table&& other); // Tab& lub void

	~Table();

private:
	void copy(const Table& other);
	void moveHelper(Table& other);

	int **pTab;
	int sizeX;
	int sizeY;
};

