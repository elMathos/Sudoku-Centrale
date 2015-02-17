#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

#include "TripleHolder.h"
#include "Cell.h"

class ExportedByDll RowHolder : public TripleHolder
{
public:
	RowHolder(Cell& cell1, Cell& cell2, Cell& cell3);
	Cell& G();
	Cell& C();
	Cell& D();
	~RowHolder();

};

