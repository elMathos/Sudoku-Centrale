#include "RegionHolder.h"
#include "ValueEliminator.h"


//TODO do we need accessors or public Cells ?
RegionHolder::RegionHolder(Region& reg) : _cNW(reg.Get_cNW()), _cN(reg.Get_cN()), _cNE(reg.Get_cNE()),
_cW(reg.Get_cW()), _cC(reg.Get_cC()), _cE(reg.Get_cE()),
_cSW(reg.Get_cSW()), _cS(reg.Get_cS()), _cSE(reg.Get_cSE())
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

set<unsigned char> RegionHolder::flagValues(ValueEliminator& valueEliminator)
{
	valueEliminator.setFlags(*this);
	return valueEliminator.availableValue();
}

bool RegionHolder::isValuePresent(unsigned char iTarget)
{
	ValueEliminator valueEliminator;
	set<unsigned char> availableValues = flagValues(valueEliminator);
	
	return availableValues.find(iTarget) != availableValues.end(); 
}

RegionHolder::~RegionHolder()
{
}


