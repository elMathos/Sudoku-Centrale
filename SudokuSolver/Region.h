#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

#include "Cell.h"
#include <string>
#include <vector>
#include <memory>
using namespace std;

class ExportedByDll Region
{
public:
	Region(string);
	Region();
	~Region();
	Region& operator=(const Region& r);
	bool IsFull();
	vector<vector<Cell>> cells;

private:
	const int L = 3;
};

