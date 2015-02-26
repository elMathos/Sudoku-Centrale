#include "ValueEliminator.h"


ValueEliminator::ValueEliminator()
{
	for (int i = 0; i < 9; i++) { _alreadySeen[i] = false; }
}


ValueEliminator::~ValueEliminator()
{
}

void ValueEliminator::flag(unsigned char iValue)
{
	_alreadySeen[iValue - 1] = true;
}

int ValueEliminator::availableValues()
{
	int count = 0;

	for (int i = 0; i < 9; i++)
	{
		count += _alreadySeen[i] ? 0 : 1;
	}

	return count;
}

set<unsigned char> ValueEliminator::availableValue()
{
	set<unsigned char> valueSet;
	for (int i = 0; i < 9; i++)
	{
		if (!_alreadySeen[i])
			valueSet.insert(i + 1);
	}

	if (valueSet.size() == 0)
		throw invalid_argument("No available value.\n");

	return valueSet;
}

//TODO argument must be const ?
void ValueEliminator::setFlags(RegionHolder& regionHolder)
{
	for (unsigned char i = 0; i < 3; i++)
	{
		for (unsigned char j = 0; j < 3; j++)
		{
			if (!regionHolder.GetCell(i, j).IsEmpty())
			{
				flag(regionHolder.GetCell(i, j));
			}
		}
	}
}

void ValueEliminator::setFlags(TripleHolder& tripleHolder)
{
	if (!tripleHolder.Cell1().IsEmpty())
		flag(tripleHolder.Cell1());
	if (!tripleHolder.Cell2().IsEmpty())
		flag(tripleHolder.Cell2());
	if (!tripleHolder.Cell3().IsEmpty())
		flag(tripleHolder.Cell3());

}

void ValueEliminator::setFlags(NineHolder& regionHolder)
{
	if (!regionHolder.GetCell(0).IsEmpty())
		flag(regionHolder.GetCell(0));
	if (!regionHolder.GetCell(1).IsEmpty())
		flag(regionHolder.GetCell(1));
	if (!regionHolder.GetCell(2).IsEmpty())
		flag(regionHolder.GetCell(2));
	if (!regionHolder.GetCell(3).IsEmpty())
		flag(regionHolder.GetCell(3));
	if (!regionHolder.GetCell(4).IsEmpty())
		flag(regionHolder.GetCell(4));
	if (!regionHolder.GetCell(5).IsEmpty())
		flag(regionHolder.GetCell(5));
	if (!regionHolder.GetCell(6).IsEmpty())
		flag(regionHolder.GetCell(6));
	if (!regionHolder.GetCell(7).IsEmpty())
		flag(regionHolder.GetCell(7));
	if (!regionHolder.GetCell(8).IsEmpty())
		flag(regionHolder.GetCell(8));

}