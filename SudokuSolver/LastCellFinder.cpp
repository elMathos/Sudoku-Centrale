#include "LastCellFinder.h"


LastCellFinder::LastCellFinder(TripleHolder& t1, TripleHolder& t2, TripleHolder& t3) : _t1(t1), _t2(t2), _t3(t3)
{
}


LastCellFinder::~LastCellFinder()
{
}

bool LastCellFinder::fill()
{
	bool values[9];

	int valuesAvailable = 0;

	if (!_t1.Cell1().IsEmpty())
	{
		values[_t1.Cell1().GetValue() - 1] = true;
		valuesAvailable++;
	}

	if (!_t1.Cell2().IsEmpty())
	{
		values[_t1.Cell2().GetValue() - 1] = true;
		valuesAvailable++;
	}

	if (!_t1.Cell3().IsEmpty())
	{
		values[_t1.Cell3().GetValue() - 1] = true;
		valuesAvailable++;
	}

	if (!_t2.Cell1().IsEmpty())
	{
		values[_t2.Cell1().GetValue() - 1] = true;
		valuesAvailable++;
	}

	if (!_t2.Cell2().IsEmpty())
	{
		values[_t2.Cell2().GetValue() - 1] = true;
		valuesAvailable++;
	}

	if (!_t2.Cell3().IsEmpty())
	{
		values[_t2.Cell3().GetValue() - 1] = true;
		valuesAvailable++;
	}

	if (!_t3.Cell1().IsEmpty())
	{
		values[_t3.Cell1().GetValue() - 1] = true;
		valuesAvailable++;
	}

	if (!_t3.Cell2().IsEmpty())
	{
		values[_t3.Cell2().GetValue() - 1] = true;
		valuesAvailable++;
	}

	if (!_t3.Cell3().IsEmpty())
	{
		values[_t3.Cell3().GetValue() - 1] = true;
		valuesAvailable++;
	}
		
	if (valuesAvailable == 8)
	{
		for (int i = 0; i < 9; i++)
		{
			if (!values[i]) //values false at rank i, ie value i+1 missing
			{
				if (_t1.Cell1().IsEmpty())
				{
					_t1.Cell1() = i + 1;
				}
				if (_t1.Cell2().IsEmpty())
				{
					_t1.Cell2() = i + 1;
				}
				if (_t1.Cell3().IsEmpty())
				{
					_t1.Cell3() = i + 1;
				}
				if (_t2.Cell1().IsEmpty())
				{
					_t2.Cell1() = i + 1;
				}
				if (_t2.Cell2().IsEmpty())
				{
					_t2.Cell2() = i+1;
				}
				if (_t2.Cell3().IsEmpty())
				{
					_t2.Cell3() = i + 1;
				}
				if (_t3.Cell1().IsEmpty())
				{
					_t3.Cell1() = i + 1;
				}
				if (_t3.Cell2().IsEmpty())
				{
					_t3.Cell2() = i + 1;
				}
				if (_t3.Cell3().IsEmpty())
				{
					_t3.Cell3() = i + 1;
				}
			}
		}
	}

	return valuesAvailable == 8;
}
