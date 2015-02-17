#include "TripleHolder.h"


TripleHolder::TripleHolder(Cell& cell1, Cell& cell2, Cell& cell3) : _cell1(cell1), _cell2(cell2), _cell3(cell3)
{

}


TripleHolder::~TripleHolder()
{
}

Cell& TripleHolder::Cell1()
{
	return _cell1;
}

Cell& TripleHolder::Cell2()
{
	return _cell2;
}

Cell& TripleHolder::Cell3()
{
	return _cell3;
}
