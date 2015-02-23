#pragma once
#include "TripleHolder.h"

class LastCellFinder
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

