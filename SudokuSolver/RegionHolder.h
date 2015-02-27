#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

class ValueEliminator;
#include "Region.h"
#include "RowHolder.h"
#include "ColumnHolder.h"

class ExportedByDll RegionHolder
{
public:
	RegionHolder(Region& reg);
	~RegionHolder();
	RowHolder TopRow();
	RowHolder TopRow() const;
	RowHolder MiddleRow();
	RowHolder MiddleRow() const;
	RowHolder BottomRow();
	RowHolder BottomRow() const;
	ColumnHolder LeftColumn();
	ColumnHolder LeftColumn() const;
	ColumnHolder MiddleColumn();
	ColumnHolder MiddleColumn() const;
	ColumnHolder RightColumn();
	ColumnHolder RightColumn() const;
	void flagValues(ValueEliminator& v);
	bool isValuePresent(unsigned char);
	bool isConsistent();
	bool isFull();

	//TODO: (also?) Make all accessors as const
	Cell& GetCell(unsigned char, unsigned char);

private:

	Cell& _cNW;
	Cell& _cN;
	Cell& _cNE;
	Cell& _cW;
	Cell& _cC;
	Cell& _cE;
	Cell& _cSW;
	Cell& _cS;
	Cell& _cSE;
};

