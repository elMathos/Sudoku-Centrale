#include "RegionHolder.h"
#include "ValueEliminator.h"


RegionHolder::RegionHolder(Region& reg) : _cNW(reg.getCell(0, 0)), _cN(reg.getCell(0, 1)), _cNE(reg.getCell(0, 2)),
_cW(reg.getCell(1, 0)), _cC(reg.getCell(1, 1)), _cE(reg.getCell(1, 2)),
_cSW(reg.getCell(2, 0)), _cS(reg.getCell(2, 1)), _cSE(reg.getCell(2, 2))
{
}

RowHolder RegionHolder::TopRow()
{
	return RowHolder(_cNW, _cN, _cNE);
}

RowHolder RegionHolder::TopRow() const
{
	return RowHolder(_cNW, _cN, _cNE);
}

RowHolder RegionHolder::MiddleRow()
{
	return RowHolder(_cW, _cC, _cE);
}

RowHolder RegionHolder::MiddleRow() const
{
	return RowHolder(_cW, _cC, _cE);
}

RowHolder RegionHolder::BottomRow()
{
	return RowHolder(_cSW, _cS, _cSE);
}

RowHolder RegionHolder::BottomRow() const
{
	return RowHolder(_cSW, _cS, _cSE);
}

ColumnHolder RegionHolder::LeftColumn()
{
	return ColumnHolder(_cNW, _cW, _cSW);
}

ColumnHolder RegionHolder::LeftColumn() const
{
	return ColumnHolder(_cNW, _cW, _cSW);
}

ColumnHolder RegionHolder::MiddleColumn()
{
	return ColumnHolder(_cN, _cC, _cS);
}

ColumnHolder RegionHolder::MiddleColumn() const
{
	return ColumnHolder(_cN, _cC, _cS);
}

ColumnHolder RegionHolder::RightColumn()
{
	return ColumnHolder(_cNE, _cE, _cSE);
}

ColumnHolder RegionHolder::RightColumn() const
{
	return ColumnHolder(_cNE, _cE, _cSE);
}

void RegionHolder::flagValues(ValueEliminator& valueEliminator)
{
	valueEliminator.setFlags(*this);
}

bool RegionHolder::isValuePresent(unsigned char iTarget)
{
	ValueEliminator valueEliminator;
	flagValues(valueEliminator);
	set<unsigned char> availableValues = valueEliminator.availableValue();
	
	return availableValues.find(iTarget) == availableValues.end();
	// if in availableValues then it is absent from the set
}

Cell& RegionHolder::getCell(unsigned char i, unsigned char j)
{
	if (i == 0 && j == 0) return _cNW;
	if (i == 0 && j == 1) return _cN;
	if (i == 0 && j == 2) return _cNE;
	if (i == 1 && j == 0) return _cW;
	if (i == 1 && j == 1) return _cC;
	if (i == 1 && j == 2) return _cE;
	if (i == 2 && j == 0) return _cSW;
	if (i == 2 && j == 1) return _cS;
	if (i == 2 && j == 2) return _cSE;
	else throw invalid_argument("i and j must be between 0 and 2.\n");
}

RegionHolder::~RegionHolder()
{
}


bool RegionHolder::isConsistent()
{
	bool consistent = true;
	set<unsigned char> alreadySeen;
	int value = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			value = getCell(i, j).getValue();
			if (value != -1 && alreadySeen.find(value) != alreadySeen.end())
			{
				consistent = false;
				break;
			}
			else if (value != -1)
				alreadySeen.insert(value);
		}		
	}

	return consistent;
}

bool RegionHolder::isFull()
{
	bool full = true;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (getCell(i, j).IsEmpty())
			{
				full = false;
				break;
			}
		}
	}

	return full;
}