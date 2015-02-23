#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif


#include "TripleHolder.h"

class ExportedByDll LastCellFinder
{
public:
	LastCellFinder(TripleHolder& t1, TripleHolder& t2, TripleHolder& t3);
	~LastCellFinder();
	bool Fill();

private:
	TripleHolder& _t1; 
	TripleHolder& _t2; 
	TripleHolder& _t3;
};

