#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

#include "Region.h"
#include "RegionHolder.h"
#include <string>
#include <vector>
#include <memory>
using namespace std;


class ExportedByDll Grid
{
public:
	Grid(vector<vector<string>>& values);
	Grid(vector<vector<Region>>& regions);
	~Grid();
	bool IsFull();
	RegionHolder HoldRegion(int i, int j);
private:
	vector<vector<Region>> _regions;
	const int M = 3;
};

