#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

class ValueEliminator;
#include "Region.h"
#include "RowHolder.h"
//#include "ValueEliminator.h"
#include "ColumnHolder.h"
#include <set>

using namespace std;

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
	set<unsigned char> FlagValues(ValueEliminator& v);
	bool IsValuePresent(unsigned char);

	//TODO: (also?) Make all accessors as const
	Cell& Get_cNW() const{ return _cNW; }
	Cell& Get_cN() const{ return _cN; }
	Cell& Get_cNE() const{ return _cNE; }
	Cell& Get_cW() const{ return _cW; }
	Cell& Get_cC() const{ return _cC; }
	Cell& Get_cE() const{ return _cE; }
	Cell& Get_cSW() const{ return _cSW; }
	Cell& Get_cS() const{ return _cS; }
	Cell& Get_cSE() const{ return _cSE; }

private:
	const int L = 3;

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

