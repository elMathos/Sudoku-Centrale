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

void ValueEliminator::setFlags(const RegionHolder& regionHolder)
{
	if (! regionHolder.Get_cNW().IsEmpty())
		flag(regionHolder.Get_cNW());
	if (!regionHolder.Get_cN().IsEmpty())
		flag(regionHolder.Get_cN());
	if (!regionHolder.Get_cNE().IsEmpty())
		flag(regionHolder.Get_cNE());
	if (!regionHolder.Get_cW().IsEmpty())
		flag(regionHolder.Get_cW());
	if (!regionHolder.Get_cC().IsEmpty())
		flag(regionHolder.Get_cC());
	if (!regionHolder.Get_cE().IsEmpty())
		flag(regionHolder.Get_cE());
	if (!regionHolder.Get_cSW().IsEmpty())
		flag(regionHolder.Get_cSW());
	if (!regionHolder.Get_cS().IsEmpty())
		flag(regionHolder.Get_cS());
	if (!regionHolder.Get_cSE().IsEmpty())
		flag(regionHolder.Get_cSE());

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