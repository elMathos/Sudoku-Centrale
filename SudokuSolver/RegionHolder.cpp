#include "RegionHolder.h"



//TODO do we need accessors or public Cells ?
RegionHolder::RegionHolder(Region& reg) : _cNW(reg.Get_cNW()), _cN(reg.Get_cNW()), _cNE(reg.Get_cNW()),
_cW(reg.Get_cNW()), _cC(reg.Get_cNW()), _cE(reg.Get_cNW())
, _cSW(reg.Get_cNW()), _cS(reg.Get_cNW()), _cSE(reg.Get_cNW())
//TODO fix the arguments in the initialisation list
{
}

//TODO : implement all accessors 


RowHolder RegionHolder::TopRow()
{
	return RowHolder(_cNW, _cN, _cNE);
}

RowHolder RegionHolder::TopRow() const
{
	return RowHolder(_cNW, _cN, _cNE);
}

//TODO 10 others as ^

set<unsigned char> RegionHolder::FlagValues(ValueEliminator& valueEliminator)
{
	valueEliminator.SetFlags(*this);
	return valueEliminator.AvailableValue();
}

bool RegionHolder::IsValuePresent(unsigned char iTarget)
{
	ValueEliminator valueEliminator;
	set<unsigned char> availableValues = FlagValues(valueEliminator);
	
	return availableValues.find(iTarget) != availableValues.end(); 
}

RegionHolder::~RegionHolder()
{
}


