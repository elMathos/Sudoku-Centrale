#include "ValueEliminator.h"


ValueEliminator::ValueEliminator()
{
}


ValueEliminator::~ValueEliminator()
{
}

void ValueEliminator::Flag(unsigned char iValue)
{
	_alreadySeen[iValue] = true;
}

int ValueEliminator::AvailableValues()
{
	int count = 0;

	//TODO : MAGIC NUMBERS
	for (int i = 0; i < 9; i++)
	{
		count += _alreadySeen[i] ? 0 : 1;
	}

	return count;
}

set<unsigned char> ValueEliminator::AvailableValue()
{
	set<unsigned char> set;
	for (int i = 0; i < 9; i++)
	{
		if (!_alreadySeen[i])
			set.insert(i);
	}

	//TODO : implement the class ExceptionOfMyAssBaby
	//if (set.count ==0)
		//throw stand

	return set;
}

void ValueEliminator::SetFlags(const RegionHolder& regionHolder)
{
	//TODO iterate on all Cells
	//TODO how to access _cNW ?
	if (! regionHolder.Get_cNW().IsEmpty())
		Flag(regionHolder.Get_cNW());

}