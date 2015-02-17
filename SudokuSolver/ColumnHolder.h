#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

#include "TripleHolder.h"

class ExportedByDll ColumnHolder : public TripleHolder
{
public:
	ColumnHolder(Cell& cell1, Cell& cell2, Cell& cell3);
	Cell& T();
	Cell& C();
	Cell& B();
	ColumnHolder();
	~ColumnHolder();
};

