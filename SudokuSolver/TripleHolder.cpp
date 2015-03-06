#include "TripleHolder.h"
#include "ValueEliminator.h"


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

void TripleHolder::flagValues(ValueEliminator& valueEliminator)
{
	valueEliminator.setFlags(*this);
}

bool TripleHolder::isValuePresent(unsigned char iTarget)
{
	ValueEliminator valueEliminator;
	flagValues(valueEliminator);
	set<unsigned char> availableValues = valueEliminator.availableValue();

	return availableValues.find(iTarget) == availableValues.end();
	// if in availableValues then it is absent from the set
}