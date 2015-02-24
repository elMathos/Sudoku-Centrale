#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

#include "Cell.h"
#include "TripleHolder.h"

class ExportedByDll NineHolder
{
public:
	NineHolder(TripleHolder&, TripleHolder&, TripleHolder&);
	~NineHolder();
	Cell& GetCell(unsigned char i);

private:
	Cell& _cell1;
	Cell& _cell2;
	Cell& _cell3;
	Cell& _cell4;
	Cell& _cell5;
	Cell& _cell6;
	Cell& _cell7;
	Cell& _cell8;
	Cell& _cell9;
};

