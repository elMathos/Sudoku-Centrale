#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

#include "Region.h"
#include "RowHolder.h"
class ExportedByDll RegionHolder
{
public:
	RegionHolder();
	RegionHolder(Region& reg);
	~RegionHolder();
	Cell AccessCell(int i, int j);
	RowHolder TopRow();
private:
	const int L = 3;
	vector<vector<Cell>> _cells;

};

