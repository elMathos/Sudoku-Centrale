#include "ColumnHolder.h"


ColumnHolder::ColumnHolder(Cell& cell1, Cell& cell2, Cell& cell3) :TripleHolder(cell1, cell2, cell3)
{
}


ColumnHolder::~ColumnHolder()
{
}

Cell& ColumnHolder::T()
{
	return Cell1();
}

Cell& ColumnHolder::C()
{
	return Cell2();
}

Cell& ColumnHolder::B()
{
	return Cell3();
}