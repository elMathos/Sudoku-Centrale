#pragma once
#include "TripleHolder.h"
#include "Cell.h"

class RowHolder : public TripleHolder
{
public:
	RowHolder(Cell& cell1, Cell& cell2, Cell& cell3);
	Cell& G();
	Cell& C();
	Cell& D();
	~RowHolder();

};

