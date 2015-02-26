#include "RegionHolder.h"
#include "ValueEliminator.h"


//TODO do we need accessors or public Cells ?
RegionHolder::RegionHolder(Region& reg) : _cNW(reg.GetCell(0, 0)), _cN(reg.GetCell(0, 1)), _cNE(reg.GetCell(0, 2)),
_cW(reg.GetCell(1, 0)), _cC(reg.GetCell(1, 1)), _cE(reg.GetCell(1, 2)),
_cSW(reg.GetCell(2, 0)), _cS(reg.GetCell(2, 1)), _cSE(reg.GetCell(2, 2))
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

Cell& RegionHolder::GetCell(unsigned char i, unsigned char j)
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


