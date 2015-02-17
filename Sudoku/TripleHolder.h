#pragma once
#include "Cell.h"

class TripleHolder
{
public:
	TripleHolder(Cell& cell1, Cell& cell2, Cell& cell3 );
	~TripleHolder();
	Cell& Cell1();
	Cell& Cell2();
	Cell& Cell3();

protected:
	Cell& _cell1;
	Cell& _cell2;
	Cell& _cell3;
};

