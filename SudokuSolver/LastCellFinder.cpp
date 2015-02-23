#include "LastCellFinder.h"


LastCellFinder::LastCellFinder(TripleHolder& t1, TripleHolder& t2, TripleHolder& t3) : _t1(t1), _t2(t2), _t3(t3)
{
}


LastCellFinder::~LastCellFinder()
{
}

bool LastCellFinder::Fill()
{
	bool values[9];

	int valuesAvailable = 0;

	//TODO : do it 9 times
	if (!_t1.Cell1().IsEmpty())
	{
		values[_t1.Cell1()] = true;
		valuesAvailable++;
	}
		
	if (valuesAvailable == 8)
	{
		//....
		//9 if to implement...
	}

	return valuesAvailable == 8;
}
