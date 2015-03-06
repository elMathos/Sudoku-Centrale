#include "NineHolder.h"
#include "ValueEliminator.h"


NineHolder::NineHolder(TripleHolder& t1, TripleHolder& t2, TripleHolder& t3) : _cell1(t1.Cell1()), _cell2(t1.Cell2()),
_cell3(t1.Cell3()), _cell4(t2.Cell1()), _cell5(t2.Cell2()),
_cell6(t2.Cell3()), _cell7(t3.Cell1()), _cell8(t3.Cell2()),
_cell9(t3.Cell3())
{
}


NineHolder::~NineHolder()
{
}

Cell& NineHolder::getCell(unsigned char i)
{
	//Careful there is an offset between i and celli+1
	if (i == 0) return _cell1;
	if (i == 1) return _cell2;
	if (i == 2) return _cell3;
	if (i == 3) return _cell4;
	if (i == 4) return _cell5;
	if (i == 5) return _cell6;
	if (i == 6) return _cell7;
	if (i == 7) return _cell8;
	if (i == 8) return _cell9;
	else throw invalid_argument("Required cell index must be between 0 and 8.\n");

}

void NineHolder::flagValues(ValueEliminator& valueEliminator)
{
	valueEliminator.setFlags(*this);
}

bool NineHolder::isValuePresent(unsigned char iTarget)
{
	ValueEliminator valueEliminator;
	flagValues(valueEliminator);
	set<unsigned char> availableValues = valueEliminator.availableValue();

	return availableValues.find(iTarget) == availableValues.end();
	// if in availableValues then it is absent from the set
}

bool NineHolder::isConsistent()
{
	bool consistent = true;
	set<unsigned char> alreadySeen;
	int value = 0;
	for (int i = 0; i < 9; i++)
	{
		value = getCell(i).getValue();
		if (alreadySeen.find(value) != alreadySeen.end())
		{
			consistent = false;
			break;
		}
		else if (value != -1)
				alreadySeen.insert(value);					
	}

	return consistent;
}

bool NineHolder::isFull()
{
	bool full = true;
	for (int i = 0; i < 9; i++)
	{
		if (getCell(i).IsEmpty())
		{
			full = false;
			break;
		}
	}

	return full;
}