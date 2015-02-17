#pragma once
#include "Cell.h"
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Region
{
public:
	Region(string);
	Region();
	~Region();
	Region& operator=(const Region& r);

private:
	vector<vector<Cell>> _cells;
	const int L = 3;
	bool IsFull();
};

