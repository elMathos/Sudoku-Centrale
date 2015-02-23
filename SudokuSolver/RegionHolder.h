#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

#include "Region.h"
#include "RowHolder.h"
#include "ValueEliminator.h"

class ExportedByDll RegionHolder
{
public:
	RegionHolder(Region& reg);
	~RegionHolder();
	RowHolder TopRow();
	RowHolder TopRow() const;

	set<unsigned char> FlagValues(ValueEliminator& v);
	bool IsValuePresent(unsigned char);

	//Make all accessors as const
	Cell& Cell_1_1() const{ return _cell_1_1; }
private:
	const int L = 3;

	//OMG so ulgy;
	Cell& _cell_1_1;
	Cell& _cell_1_2;
	Cell& _cell_1_3;
	Cell& _cell_2_1;
	Cell& _cell_2_2;
	Cell& _cell_2_3;
	Cell& _cell_3_1;
	Cell& _cell_3_2;
	Cell& _cell_3_3;
};

